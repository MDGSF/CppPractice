#ifndef MPMC_QUEUE_HPP
#define MPMC_QUEUE_HPP

#include <atomic>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <vector>

template <typename T>
class MPMCQueue final {
 public:
  MPMCQueue(int size) : m_size{size}, m_buffer{std::vector<T>(size)} {};
  ~MPMCQueue() = default;

  MPMCQueue(const MPMCQueue&) = delete;
  MPMCQueue& operator=(const MPMCQueue&) = delete;

  MPMCQueue(MPMCQueue&& s) = delete;
  MPMCQueue& operator=(MPMCQueue&& s) = delete;

  bool pop(T& item);
  bool push(T item);
  void stop();

 private:
  bool is_full(uint64_t current) const noexcept;
  bool is_empty(uint64_t current) const noexcept;

  int m_size = 0;
  std::vector<T> m_buffer = {};
  std::atomic<uint64_t> m_read = 0;
  std::atomic<uint64_t> m_write = 0;
  std::mutex m_mutex = {};
  std::condition_variable m_empty = {};
  std::condition_variable m_full = {};
  bool m_stoped = false;
};

template <typename T>
bool MPMCQueue<T>::pop(T& item) {
  std::unique_lock<std::mutex> m(m_mutex);

  while (is_full(m_read)) {
    m_empty.wait(m);
  }

  if (m_stoped) {
    return false;
  }

  auto data = std::move(m_buffer[m_read % m_size]);
  m_read++;

  m.unlock();
  m_full.notify_one();

  item = std::move(data);

  return true;
}

template <typename T>
bool MPMCQueue<T>::push(T item) {
  std::unique_lock<std::mutex> m(m_mutex);

  while (is_full(m_write)) {
    m_full.wait(m);
  }

  if (m_stoped) {
    return false;
  }

  m_buffer[m_write % m_size] = std::move(item);
  m_write++;

  m.unlock();
  m_empty.notify_one();

  return true;
}

template <typename T>
void MPMCQueue<T>::stop() {
  std::unique_lock<std::mutex> m(m_mutex);
  m_stoped = true;
  m.unlock();
  m_empty.notify_one();
  m_full.notify_one();
}

template <typename T>
bool MPMCQueue<T>::is_full(uint64_t current) const noexcept {
  return !m_stoped && current >= m_read + m_size;
}

template <typename T>
bool MPMCQueue<T>::is_empty(uint64_t current) const noexcept {
  return !m_stoped && current >= m_write;
}

#endif
