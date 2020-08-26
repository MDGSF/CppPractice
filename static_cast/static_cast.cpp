#include <iostream>
#include <vector>

struct B {
  int m = 0;
  void hello() const { std::cout << "Hello world, this is B!\n"; }
};

struct D : B {
  void hello() const { std::cout << "Hello world, this is D!\n"; }
};

enum class E { ONE = 1, TWO, THREE };

enum EU { ONE = 1, TWO, THREE };

int main() {
  // 1. initializing conversion
  int n = static_cast<int>(3.14);
  std::cout << "n = " << n << std::endl;
  std::vector<int> v = static_cast<std::vector<int>>(10);
  std::cout << "v.size() = " << v.size() << std::endl;

  // 2. static downcast
  D d;
  B& br = d;  // upcast via implicit conversion
  br.hello();
  D& another_d = static_cast<D&>(br);  // downcast
  another_d.hello();

  // 3. lvalue to xvalue
  std::vector<int> v2 = static_cast<std::vector<int>&&>(v);
  std::cout << "after move, v.size() = " << v.size() << std::endl;

  // 4. discarded-value expression
  static_cast<void>(v2.size());

  // 5. inverse of implicit conversion
  void* nv = &n;
  int* ni = static_cast<int*>(nv);
  // int* ni = reinterpret_cast<int*>(nv); // 用 reinterpret_cast 好像也可以
  std::cout << "*ni = " << *ni << std::endl;

  // 6. array-to-pointer followed by upcast
  D a[10];
  B* dp = static_cast<B*>(a);

  // 7. scoped enum to int or float
  E e = E::ONE;
  int one = static_cast<int>(e);
  std::cout << one << std::endl;

  // 8. int to enum, enum to another enum
  E e2 = static_cast<E>(one);
  EU eu = static_cast<EU>(e2);

  // 9. pointer to member upcast
  int D::*pm = &D::m;
  std::cout << br.*static_cast<int B::*>(pm) << std::endl;

  // 10. void* to any type
  void* voidp = &e;
  std::vector<int>* p = static_cast<std::vector<int>*>(voidp);
  return 0;
}
