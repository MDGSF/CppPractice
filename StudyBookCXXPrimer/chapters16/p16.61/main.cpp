#include <iostream>
#include <memory>

// 声明
template <typename T, typename... Args>
std::shared_ptr<T> my_make_shared(Args&&...);

// 定义
template <typename T, typename... Args>
inline std::shared_ptr<T>
my_make_shared(Args&&... args) {
  std::shared_ptr<T> ret( new T(std::forward<Args>(args)...) );
  return ret;
}

int main() {
  auto p = my_make_shared<int>(42);
  std::cout << *p << std::endl;

  auto p2 = my_make_shared<std::string>(10, 'c');
  std::cout << *p2 << std::endl;
  return 0;
}
