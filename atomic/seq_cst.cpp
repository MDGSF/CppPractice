#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

int main() {
  std::atomic<int> counter = {0};
  std::vector<std::thread> vt;
  for (int i = 0; i < 100; i++) {
    vt.emplace_back([&]() { counter.fetch_add(1, std::memory_order_seq_cst); });
  }
  for (auto& t : vt) {
    t.join();
  }
  std::cout << "current counter:" << counter << std::endl;
  return 0;
}
