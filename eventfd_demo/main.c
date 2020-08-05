#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/eventfd.h>
#include <unistd.h>

#define handle_error(msg) \
  do {                    \
    perror(msg);          \
    exit(EXIT_FAILURE);   \
  } while (0)

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <num>...\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int efd = eventfd(0, 0);
  if (efd == -1) {
    handle_error("eventfd");
  }

  switch (fork()) {
    case 0:
      for (int i = 1; i < argc; i++) {
        printf("Child writing %s to efd\n", argv[i]);
        uint64_t u = strtoull(argv[i], NULL, 0);
        ssize_t s = write(efd, &u, sizeof(uint64_t));
        if (s != sizeof(uint64_t)) {
          handle_error("write");
        }
      }
      printf("Child completed write loop\n");
      exit(EXIT_SUCCESS);
    case -1:
      handle_error("fork");
    default:
      sleep(2);

      printf("Parent about to read\n");
      uint64_t u = 0;
      ssize_t s = read(efd, &u, sizeof(uint64_t));
      if (s != sizeof(uint64_t)) {
        handle_error("read");
      }
      printf("Parent read %llu (0x%llx) from efd\n", (unsigned long long)u,
             (unsigned long long)u);
      exit(EXIT_SUCCESS);
  }
  return 0;
}
