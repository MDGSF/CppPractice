#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void test() {
  printf("test start\n");
  longjmp(buf, 20);
  printf("test end\n");
}

int main() {
  int ret = setjmp(buf);
  if (ret) {
    printf("1, ret = %d\n", ret);
  } else {
    printf("2\n");
    test();
  }
  return 0;
}
