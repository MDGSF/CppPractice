#include <iostream>
#include <memory>

void foo(std::shared_ptr<int> i) {
  (*i)++;
}

int main() {
  auto pointer = std::make_shared<int>(10);
  foo(pointer);
  std::cout << *pointer << std::endl;

  auto pointer2 = pointer;
  auto pointer3 = pointer;
  int *p = pointer.get();
  std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;
  std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;
  std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;

  pointer2.reset();
  std::cout << "reset pointer2:" << std::endl;
  std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;
  std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;
  std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;

  pointer3.reset();
  std::cout << "reset pointer3:" << std::endl;
  std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;
  std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;
  std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;
  return 0;
}
