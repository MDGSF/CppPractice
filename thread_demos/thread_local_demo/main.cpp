#include <iostream>
#include <thread>

using namespace std;

int main() {
  // static int n = 0;
  thread_local int n = 0;

  auto f = [&](int x) {
    n += x;
    cout << n;
    cout << ", tid=" << this_thread::get_id() << endl;
  };

  thread t1(f, 10);
  thread t2(f, 20);

  t1.join();
  t2.join();

  return 0;
}
