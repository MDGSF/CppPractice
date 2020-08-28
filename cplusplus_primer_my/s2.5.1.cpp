#include <iostream>

typedef char* pstring;

// cstr 是指向 char 的常量指针
// char *const cstr = 0;
// 顶层 const
const pstring cstr = 0;

// ps 是一个指针，它的对象是指向 char 的常量指针
// 底层 const
const pstring* ps;

int main() {
  char c = 'a';
  // cstr = &c;
  ps = &cstr;
  return 0;
}
