#include <iostream>
#include <stdio.h>
#include <stdint.h>

typedef void (*FuncPtr)();

class Empty {};

class Virtual {
 public:
  virtual void foo() { printf("Virtual::foo()\n"); }
};

class A {
 public:
  virtual void foo() { printf("A::foo()\n"); }
  virtual void bar() { printf("A::bar()\n"); }
  int m_num1;
  int m_num2;
};

void test1() {
  printf("------------ test1 start\n");
  Empty empty;
  printf("sizeof(Empty) = %lu\n", sizeof(Empty));
  printf("sizeof(empty) = %lu\n", sizeof(empty));

  Virtual v;
  printf("sizeof(Virtual) = %lu\n", sizeof(Virtual));
  printf("sizeof(v) = %lu\n", sizeof(v));

  A a;
  printf("sizeof(A) = %lu\n", sizeof(A));
  printf("sizeof(a) = %lu\n", sizeof(a));
  printf("------------ test1 end\n\n");
}

void test2() {
  printf("------------ test2 start\n");
  A a;
  // 对象a前8个字节的地址
  int64_t* virtual_table_address_container_address = (int64_t*)&a;
  // 对象a前8个字节地址中的内容，也就是虚表的地址
  int64_t* virtual_table_address = (int64_t*)(*virtual_table_address_container_address);
  // 虚表中第一个元素的地址
  int64_t* virtual_table_p0 = virtual_table_address;
  // 虚表中第二个元素的地址
  int64_t* virtual_table_p1 = virtual_table_address + 1;
  // 虚表中第一个元素地址中的内容
  FuncPtr foo_func_ptr = (FuncPtr)(*virtual_table_p0);
  // 虚表中第二个元素地址中的内容
  FuncPtr bar_func_ptr = (FuncPtr)(*virtual_table_p1);
  foo_func_ptr();
  bar_func_ptr();
  printf("------------ test2 end\n\n");
}

int main() {
  test1();
  test2();
  return 0;
}
