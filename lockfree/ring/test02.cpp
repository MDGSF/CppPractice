#include <atomic>
#include <iostream>
#include <map>
#include <set>
#include <thread>
#include <vector>
#include <chrono>
#include "ring02.hpp"

const int range = 10000;
const int producer_number = 100;
const int consumer_number = 200;
const int max_data_number = range * producer_number;
std::atomic<int> data_count;
Ring<int>* ring;
std::map<int, int>* received;

void producer(int i, int start_number, int range) {
  int end_number = start_number + range;
  for (int i = start_number; i < end_number;) {
    if (ring->push(i)) {
      i += 1;
    } else {
      // std::cout << "producer start_number: " << start_number << ", i: " << i
      //           << ", failed" << std::endl;
    }
  }
  std::cout << "producer[" << i << "] finished" << std::endl;
}

void consumer(int i) {
  auto& m = received[i];
  for (;;) {
    int data = -1;
    if (ring->pop(data)) {
      m[data] += 1;
      if (data_count.fetch_add(1) >= max_data_number) {
        break;
      }
    } else {
      int count = data_count.load();
      if (count >= max_data_number) {
        break;
      }
      // std::cout << "consumer failed: " << count << std::endl;
    }
  }
  std::cout << "consumer[" << i << "] finished" << std::endl;
}

int main() {
  data_count.store(0);
  ring = new Ring<int>(100);
  received = new std::map<int, int>[consumer_number];

  auto start = std::chrono::high_resolution_clock::now();

  std::thread producers[producer_number];
  for (int i = 0; i < producer_number; ++i) {
    int start_number = range * i;
    producers[i] = std::thread(producer, i, start_number, range);
  }

  std::thread consumers[consumer_number];
  for (int i = 0; i < consumer_number; ++i) {
    consumers[i] = std::thread(consumer, i);
  }

  for (int i = 0; i < producer_number; ++i) {
    producers[i].join();
  }

  for (int i = 0; i < consumer_number; ++i) {
    consumers[i].join();
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "运行时间为：" << duration.count() << " 微秒" << std::endl;

  std::cout << "transfer finished, start statistics" << std::endl;

  // 检查收到的个数和发送的个数是否一样。
  int map_data_number_counter = 0;
  for (int i = 0; i < consumer_number; ++i) {
    auto m = received[i];
    map_data_number_counter += m.size();
    std::cout << "i: " << i << ", size: " << m.size() << std::endl;
  }
  std::cout << "map_data_number_counter: " << map_data_number_counter
            << std::endl;
  if (max_data_number != map_data_number_counter) {
    std::cout << "invalid number count: " << map_data_number_counter
              << ", expected: " << max_data_number << std::endl;
    return 0;
  }

  // 去重之后，再检查收到的个数和发送的个数是否一样。
  std::set<int> unique_numbers;
  for (int i = 0; i < consumer_number; ++i) {
    auto m = received[i];
    for (auto it = m.begin(); it != m.end(); ++it) {
      int num = it->first;
      int count = it->second;
      if (count > 1) {
        std::cout << "found invalid number count, " << num << ", " << count
                  << std::endl;
        return 0;
      }
      if (unique_numbers.find(num) != unique_numbers.end()) {
        std::cout << "found invalid number, already exists, " << num
                  << std::endl;
        return 0;
      }
      unique_numbers.insert(num);
    }
  }
  std::cout << "unique_numbers size: " << unique_numbers.size() << std::endl;
  if (max_data_number != unique_numbers.size()) {
    std::cout << "invalid number count: " << unique_numbers.size()
              << ", expected: " << max_data_number << std::endl;
    return 0;
  }

  // 检查发送的数字和接收到的数字是否一样
  for (int i = 0; i < max_data_number; ++i) {
    if (unique_numbers.find(i) == unique_numbers.end()) {
      std::cout << "number not found: " << i << std::endl;
      return 0;
    }
  }

  std::cout << "Everything is ok!!!" << std::endl;

  return 0;
}
