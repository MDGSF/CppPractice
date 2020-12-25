#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("usage: shm1 name length\n");
    return 0;
  }

  const char *name = argv[1];
  off_t length = atoi(argv[2]);

  int fd = shm_open(name, O_RDWR | O_CREAT, FILE_MODE);
  if (fd == -1) {
    printf("shm_open failed, err = %s\n", strerror(errno));
    return -1;
  }

  ftruncate(fd, length);

  char *ptr = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

  printf("success\n");
  return 0;
}
