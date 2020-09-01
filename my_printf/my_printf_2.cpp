#include <iostream>

template<typename T0, typename... T>
void printf2(T0 t0, T... t) {
  std::cout << t0 << std::endl;
  if constexpr (sizeof...(t) > 0) {
    printf2(t...);
  }
}

int main() {
  printf2(1, 2, "123", 1.1);
  return 0;
}
