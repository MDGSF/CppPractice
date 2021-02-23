#include <cassert>
#include <chrono>
#include <future>
#include <iostream>
#include <thread>

using namespace std;

bool is_prime(int x) {
  cout << "Calculating. Please, wait...\n";
  for (int i = 2; i < x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  std::future<bool> fut = std::async(is_prime, 2);
  bool ret = fut.get();

  if (ret) {
    cout << "Is primer.\n";
  } else {
    cout << "Is not primer.\n";
  }

  return 0;
}
