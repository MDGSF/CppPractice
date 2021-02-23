#include <cassert>
#include <chrono>
#include <future>
#include <iostream>
#include <thread>

using namespace std;

int main() {
  auto task = [](auto x) {
    this_thread::sleep_for(std::chrono::seconds(x));
    cout << "sleep for " << x << endl;
    return x;
  };

  auto f = std::async(task, 10);

  f.wait();

  assert(f.valid());
  cout << f.get() << endl;
  assert(f.valid());

  return 0;
}
