/*
多个生产者，多个消费者。
每个消息只能被消费一次。
*/
#ifndef RING02_HPP
#define RING02_HPP

#include <atomic>
#include <thread>
#include <vector>

template <typename T>
class Ring {
 public:
  Ring<T>(int capacity) :
    buffer_(new Cell[find_next_highest_power_of_2(capacity)]),
    mask_(find_next_highest_power_of_2(capacity) - 1)
  {
    int buffer_size = mask_ + 1;
    for (int i = 0; i < buffer_size; ++i) {
      buffer_[i].sequence_.store(i, std::memory_order_relaxed);
    }
    enqueue_pos_.store(0, std::memory_order_relaxed);
    dequeue_pos_.store(0, std::memory_order_relaxed);
  }
  virtual ~Ring() { delete[] buffer_; }
  Ring(const Ring&) = delete;
  Ring& operator=(const Ring&) = delete;
  Ring(Ring&&) = default;
  Ring& operator=(Ring&&) = default;

  bool push(T data) {
    Cell* cell = nullptr;
    size_t pos = enqueue_pos_.load(std::memory_order_relaxed);
    for (;;) {
      cell = &buffer_[pos & mask_];
      size_t seq = cell->sequence_.load(std::memory_order_acquire);
      intptr_t diff = (intptr_t)seq - (intptr_t)pos;
      if (diff == 0) {
        if (enqueue_pos_.compare_exchange_weak(pos, pos + 1,
                                               std::memory_order_relaxed)) {
          break;
        }
      } else if (diff < 0) {
        return false;
      } else {
        pos = enqueue_pos_.load(std::memory_order_relaxed);
      }
    }

    cell->data_ = std::move(data);
    cell->sequence_.store(pos + 1, std::memory_order_release);
    return true;
  }

  bool pop(T& data) {
    Cell* cell = nullptr;
    size_t pos = dequeue_pos_.load(std::memory_order_relaxed);
    for (;;) {
      cell = &buffer_[pos & mask_];
      size_t seq = cell->sequence_.load(std::memory_order_acquire);
      intptr_t diff = (intptr_t)seq - (intptr_t)(pos + 1);
      if (diff == 0) {
        if (dequeue_pos_.compare_exchange_weak(pos, pos + 1,
                                               std::memory_order_relaxed)) {
          break;
        }
      } else if (diff < 0) {
        return false;
      } else {
        pos = dequeue_pos_.load(std::memory_order_relaxed);
      }
    }

    data = std::move(cell->data_);
    cell->sequence_.store(pos + mask_ + 1, std::memory_order_release);
    return true;
  }

 private:
  struct Cell {
    std::atomic<size_t> sequence_;
    T data_;
  };

  uint32_t find_next_highest_power_of_2(uint32_t capacity) {
    capacity -= 1;
    capacity |= capacity >> 1;
    capacity |= capacity >> 2;
    capacity |= capacity >> 4;
    capacity |= capacity >> 8;
    capacity |= capacity >> 16;
    return capacity + 1;
  }

  static size_t const cacheline_size = 64;
  typedef char chacheline_pad_t[cacheline_size];

  chacheline_pad_t pad0_;
  Cell* const buffer_;
  size_t const mask_;
  chacheline_pad_t pad1_;
  std::atomic<size_t> dequeue_pos_;
  chacheline_pad_t pad2_;
  std::atomic<size_t> enqueue_pos_;
  chacheline_pad_t pad3_;
};

#endif
