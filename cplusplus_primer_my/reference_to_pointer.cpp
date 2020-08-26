#include <iostream>

int main() {
  int i = 42;
  int* p;       // p 是一个int型指针
  int*& r = p;  // r 是一个对指针 p 的引用

  r = &i;  // r 引用了一个指针，因此给 r 赋值 &i 就是令 p 指向 i
  *r = 0;  //解引用 r 得到 i，也就是 p 指向的对象，将 i 的值改为 0
  return 0;
}
