#include <cassert>
#include <cstdint>
#include <iostream>

int f() { return 42; }

int main() {
  int i = 7;

  // error: static_cast from 'int *' to 'std::uintptr_t' (aka 'unsigned long')
  // is not allowed
  // std::uintptr_t v1 = static_cast<std::uintptr_t>(&i);

  std::uintptr_t v1 = reinterpret_cast<std::uintptr_t>(&i);
  std::cout << "The value of &i is 0x" << std::hex << v1 << std::endl;
  int* p1 = reinterpret_cast<int*>(v1);
  assert(p1 == &i);
  std::cout << "p1 = 0x" << std::hex << p1 << std::endl;

  void (*fp1)() = reinterpret_cast<void (*)()>(f);
  // fp1(); //undefined behavior
  int (*fp2)() = reinterpret_cast<int (*)()>(fp1);
  std::cout << std::dec << fp2() << std::endl;

  char* p2 = reinterpret_cast<char*>(&i);
  if (p2[0] == '\x7') {
    std::cout << "This system is little-endian\n";
  } else {
    std::cout << "This system is big-endian\n";
  }

  reinterpret_cast<unsigned int&>(i) = 42;
  std::cout << i << std::endl;

  [[maybe_unused]] const int& const_iref = i;
  // error: reinterpret_cast from 'const int' to 'int &' casts away qualifiers
  // use const_cast instead
  // int& iref = reinterpret_cast<int&>(const_iref);
  return 0;
}
