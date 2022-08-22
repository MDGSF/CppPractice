#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <thread>
#include <signal.h>

void sig_handler(int sig) {
  printf("recieve signal %d\n", sig);
  exit(1);
}

int main() {
  //signal(SIGPIPE, SIG_IGN);  // connection reset
  signal(SIGPIPE, sig_handler);  // connection reset
  signal(SIGQUIT, sig_handler);
  signal(SIGINT, sig_handler);  // ctrl + c
  signal(SIGTERM, sig_handler);
  signal(SIGHUP, sig_handler);  // close tty
  signal(SIGUSR1, sig_handler);
  signal(SIGKILL, sig_handler);
  signal(SIGSEGV, sig_handler);
  signal(SIGBUS, sig_handler);

  int ret = 0;
  int pipe_parent_to_child[2] = {0};
  ret = pipe(pipe_parent_to_child);
  if (ret != 0) {
    printf("pipe create pipe_parent_to_child failed\n");
    return -1;
  }

  int pipe_child_read = pipe_parent_to_child[0];
  int pipe_parent_write = pipe_parent_to_child[1];

  printf("pipe_child_read = %d\n", pipe_child_read);
  printf("pipe_parent_write = %d\n", pipe_parent_write);

  int pipe_child_to_parent[2] = {0};
  ret = pipe(pipe_child_to_parent);
  if (ret != 0) {
    printf("pipe create pipe_child_to_parent failed\n");
    return -1;
  }

  int pipe_parent_read = pipe_child_to_parent[0];
  int pipe_child_write = pipe_child_to_parent[1];

  printf("pipe_parent_read = %d\n", pipe_parent_read);
  printf("pipe_child_write = %d\n", pipe_child_write);

  pid_t cpid = fork();
  if (cpid == -1) {
    printf("fork failed\n");
    return -1;
  } else if (cpid == 0) {
    // child process

    printf("child process, pid = %u\n", getpid());
    printf("child process, ppid = %u\n", getppid());

    close(pipe_parent_write);
    close(pipe_parent_read);

    ret = dup2(pipe_child_read, STDIN_FILENO);
    if (ret < 0) {
      printf("dup2 failed\n");
      return -1;
    }
    ret = dup2(pipe_child_write, STDOUT_FILENO);
    if (ret < 0) {
      printf("dup2 failed\n");
      return -1;
    }
    close(pipe_child_read);
    close(pipe_child_write);

    // only return if error occured.
    ret = execl("test", "test", NULL);
    if (ret != 0) {
      printf("execlp failed, ret = %d\n", ret);
      return -1;
    }

  } else {
    // parent process

    printf("parent process, pid = %u\n", getpid());
    printf("parent process, ppid = %u\n", getppid());

    close(pipe_child_write);
    close(pipe_child_read);

    std::thread t([&]() {
      printf("parent read thread start\n");
      while (true) {
        char buf[1024] = {0};
        while (read(pipe_parent_read, buf, 1024) > 0) {
          std::cout << "[parent read]: " << std::string(buf);
        }
      }
    });

    for (int i = 0; i < 10000; ++i) {
      char send_buf[1024] = {0};
      sprintf(send_buf, "%s %d\n", "hello", i);
      printf("[parent write]: %s", send_buf);
      ret = write(pipe_parent_write, send_buf, strlen(send_buf));
      if (ret < 0) {
        printf("ret = %d, errno = %d\n", ret, errno);
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    close(pipe_parent_write);
    close(pipe_parent_read);

    printf("parent end\n");
  }

  return 0;
}
