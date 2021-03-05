#include <iostream>

using namespace std;

template <typename T>
class TypeToID {
 public:
  static int const ID = -1;
};

template <>
class TypeToID<uint8_t> {
 public:
  static int const ID = 0;
};

template <>
class TypeToID<uint16_t> {
 public:
  static int const ID = 1;
};

template <>
class TypeToID<uint32_t> {
 public:
  static int const ID = 2;
};

template <>
class TypeToID<uint64_t> {
 public:
  static int const ID = 3;
};

template <>
class TypeToID<float> {
 public:
  static int const ID = 0xF10A7;
};

template <>
class TypeToID<void*> {
 public:
  static int const ID = 0x401d;
};

template <typename T>
class TypeToID<T*> {
 public:
  typedef T SameAsT;
  static int const ID = 0x80000000;
};

int main() {
  cout << TypeToID<uint8_t>::ID << endl;
  cout << TypeToID<uint16_t>::ID << endl;
  cout << TypeToID<uint32_t>::ID << endl;
  cout << TypeToID<uint64_t>::ID << endl;
  cout << TypeToID<float>::ID << endl;
  cout << TypeToID<void*>::ID << endl;

  cout << TypeToID<double>::ID << endl;

  cout << TypeToID<float*>::ID << endl;
  cout << TypeToID<TypeToID<float*>::SameAsT>::ID << endl;

  return 0;
}
