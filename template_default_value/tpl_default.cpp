#include <iostream>

template<typename T = int, typename U = int>
auto add(T x, U y) -> decltype(x+y) {
  return x + y;
}
