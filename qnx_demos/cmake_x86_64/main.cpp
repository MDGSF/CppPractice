#include <iostream>
#include <thread>

void thread_function() {
  for (int i = 0; i < 10000; i++) {
    std::cout << "thread function Executing" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
}

int main() {
  std::thread threadObj(thread_function);
  for (int i = 0; i < 10000; i++) {
    std::cout << "Display From MainThread" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
  threadObj.join();
  std::cout << "Exit of Main function" << std::endl;
  return 0;
}
