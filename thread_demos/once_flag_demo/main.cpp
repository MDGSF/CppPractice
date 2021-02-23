#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

static once_flag flag;

int main() {
  auto f = []() {
    cout << "tid=" << this_thread::get_id() << endl;

    std::call_once(flag, []() { cout << "only once" << endl; });
  };

  thread t1(f);
  thread t2(f);

  t1.join();
  t2.join();

  return 0;
}
