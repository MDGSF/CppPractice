/*
存在问题：
1. producer 更新了 tail_，但是数据还没有写入完成。
2. consumer 就可能读取到写入了一半的数据。
*/

#ifndef RING01_HPP
#define RING01_HPP

#include <atomic>
#include <thread>
#include <vector>

template <typename T>
class Ring {
 public:
  Ring<T>(int capacity)
      : capacity_(find_next_highest_power_of_2(capacity)),
        mask_(capacity_ - 1),
        head_(0),
        tail_(0),
        elements_{std::vector<T>(capacity_)} {}
  virtual ~Ring() = default;
  Ring(const Ring&) = delete;
  Ring& operator=(const Ring&) = delete;
  Ring(Ring&&) = default;
  Ring& operator=(Ring&&) = default;

  bool push(T item) {
    uint64_t old_head = head_.load();
    uint64_t old_tail = tail_.load();
    if (is_full(old_head, old_tail)) {
      return false;
    }

    uint64_t new_tail = (old_tail + 1) & mask_;
    if (!tail_.compare_exchange_strong(old_tail, new_tail)) {
      return false;
    }

    elements_[new_tail] = std::move(item);

    return true;
  }

  bool pop(T& out) {
    uint64_t old_head = head_.load();
    uint64_t old_tail = tail_.load();
    if (is_empty(old_head, old_tail)) {
      return false;
    }

    uint64_t new_head = (old_head + 1) &mask_;
    if (!head_.compare_exchange_strong(old_head, new_head)) {
      return false;
    }

    out = std::move(elements_[new_head]);

    return true;
  }

  bool is_full(uint64_t head, uint64_t tail) {
    return (head - tail == 1) || (head == 0 && tail == capacity_ - 1);
  }

  bool is_empty(uint64_t head, uint64_t tail) { return head == tail; }

 private:
  uint32_t find_next_highest_power_of_2(uint32_t capacity) {
    capacity -= 1;
    capacity |= capacity >> 1;
    capacity |= capacity >> 2;
    capacity |= capacity >> 4;
    capacity |= capacity >> 8;
    capacity |= capacity >> 16;
    return capacity + 1;
  }

  uint32_t capacity_;
  uint32_t mask_;
  std::atomic<uint64_t> head_;
  std::atomic<uint64_t> tail_;
  std::vector<T> elements_;
};

#endif
