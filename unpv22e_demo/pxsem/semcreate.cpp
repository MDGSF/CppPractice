#include <fcntl.h>
#include <semaphore.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

sem_t *Sem_open(const char *pathname, int oflag, ...) {
  if (oflag & O_CREAT) {
    va_list ap;
    va_start(ap, oflag);
    mode_t mode = va_arg(ap, mode_t);
    uint32_t value = va_arg(ap, uint32_t);
    sem_t *sem = sem_open(pathname, oflag, mode, value);
    if (sem == SEM_FAILED) {
      printf("sem_open error for %s\n", pathname);
      va_end(ap);
      return NULL;
    }
    va_end(ap);
    return sem;
  }
  sem_t *sem = sem_open(pathname, oflag);
  if (sem == SEM_FAILED) {
    printf("sem_open error for %s\n", pathname);
    return NULL;
  }
  return sem;
}

int main(int argc, char **argv) {
  int flags = O_RDWR | O_CREAT;
  uint32_t value = 1;
  int c = 0;
  while ((c = getopt(argc, argv, "ei:")) != -1) {
    switch (c) {
      case 'e':
        flags |= O_EXCL;
        break;
      case 'i':
        value = atoi(optarg);
        break;
    }
  }
  if (optind != argc - 1) {
    printf("usage: semcreate [ -e ] [ -i initalvalue ] <name>\n");
    return 0;
  }

  sem_t *sem = Sem_open(argv[optind], flags, FILE_MODE, value);

  sem_close(sem);
  return 0;
}
