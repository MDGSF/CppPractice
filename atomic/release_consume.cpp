#include <atomic>
#include <iostream>
#include <thread>

int main() {
  std::atomic<int*> ptr(nullptr);
  int v;
  std::thread producer([&]() {
    int* p = new int(42);
    v = 1024;
    ptr.store(p, std::memory_order_release);
  });
  std::thread consumer([&]() {
    int* p;
    while (!(p = ptr.load(std::memory_order_consume)))
      ;
    std::cout << "p: " << *p << std::endl;
    std::cout << "v: " << v << std::endl;
  });
  producer.join();
  consumer.join();
  return 0;
}
