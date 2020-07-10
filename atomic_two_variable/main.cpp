// g++ -std=c++0x -pthread main.cpp
#include <stdio.h>
#include <iostream>
#include <thread>

int num1 = 0;
int num2 = 0;

void Thread1() {
  for (int i = 0; i <= 10000; i++) {
    // 先写 num1, 再写 num2
    num1 = i;
    num2 = i;
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
}

void Thread2(int tid) {
  int iPreNum = -1;
  while (true) {
    // 先读 num2, 再读 num1
    int iCurNum2 = num2;
    int iCurNum1 = num1;
    if (iCurNum1 == iCurNum2) {
      if (iCurNum1 != iPreNum) {
        if (iCurNum1 < iPreNum) {
          printf("failed");
          exit(0);
        }

        iPreNum = iCurNum1;
        printf("[%d] num = %d\n", tid, iPreNum);
        if (iPreNum >= 10000) {
          break;
        }
      }
    } else {
      printf("[%d] num1 = %d, num2 = %d\n", tid, iCurNum1, iCurNum2);
    }
  }
}

int main() {
  std::thread myThreads[100];
  for (int i = 0; i < 100; i++) {
    myThreads[i] = std::thread(Thread2, i);
  }
  std::thread t1(Thread1);

  t1.join();
  for (int i = 0; i < 100; i++) {
    myThreads[i].join();
  }
  return 0;
}
