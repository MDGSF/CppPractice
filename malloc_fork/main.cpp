#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  char * p = (char*)malloc(1024);
  strcpy(p, "hello");
  printf("p = %s\n", p);
  int ret = fork();
  if (ret < 0) {
    printf("fork error\n");
    return -1;
  } else if (ret == 0) {
    // child
    printf("child p = %s\n", p);
    strcpy(p, "child");
    printf("child p = %s\n", p);
  } else {
    // parent
    sleep(3);
    printf("parent p = %s\n", p);
  }
  return 0;
}
