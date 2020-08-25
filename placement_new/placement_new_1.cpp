#include <iostream>

int main() {
  // buffer on stack
  unsigned char buf[sizeof(int) * 2];

  // placement new in buf
  int *p0 = new (buf) int(3);
  int *p1 = new (buf + sizeof(int)) int(5);

  int *pBuf0 = (int *)buf;
  int *pBuf1 = (int *)(buf + sizeof(int));

  std::cout << "p0 = " << p0 << ", " << *p0 << std::endl;
  std::cout << "p1 = " << p1 << ", " << *p1 << std::endl;
  std::cout << "pBuf0 = " << pBuf0 << ", " << *pBuf0 << std::endl;
  std::cout << "pBuf1 = " << pBuf1 << ", " << *pBuf1 << std::endl;

  return 0;
}
