#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/eventfd.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int i = 0;
  switch (i) {
    case 0:
      printf("case 0\n");
      exit(EXIT_SUCCESS);
    default:
      printf("case default\n");
      exit(EXIT_SUCCESS);
    case -1:
      printf("case -1\n");
      exit(EXIT_SUCCESS);
  }
  return 0;
}
