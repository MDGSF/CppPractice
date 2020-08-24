#include <stdio.h>
#include <atomic>

int main() {
  std::atomic<int> ai;
  ai = 1;
  int num = 2;
  ai.compare_exchange_weak(num, 10, std::memory_order_release,
                           std::memory_order_relaxed);

  printf("num = %d, ai = %d\n", num, ai.load(std::memory_order_relaxed));

  return 0;
}
