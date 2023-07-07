/*
 * Copyright 2018 Universidad Carlos III de Madrid
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef GRPPI_COMMON_MPMC_QUEUE_H
#define GRPPI_COMMON_MPMC_QUEUE_H

#include <atomic>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <vector>

template <typename T>
class mpmc_queue {
 public:
  using value_type = T;

  mpmc_queue<T>(int q_size)
    : size{q_size},
      buffer{std::vector<T>(q_size)},
      pread{0},
      pwrite{0},
      stoped{false} {}

  mpmc_queue(mpmc_queue&& q)
    : size{q.size},
      buffer{std::move(q.buffer)},
      pread{q.pread.load()},
      pwrite{q.pwrite.load()},
      m{},
      empty{},
      full{},
      stoped(q.stoped) {}

  mpmc_queue(const mpmc_queue&) = delete;
  mpmc_queue& operator=(const mpmc_queue&) = delete;

  bool pop(T& item);
  bool push(T item);
  void stop();
  int get_size() {
    return pwrite - pread;
  }

 private:
  bool is_full(unsigned long long current) const noexcept;
  bool is_empty(unsigned long long current) const noexcept;

  int size;
  std::vector<T> buffer;

  std::atomic<uint64_t> pread;
  std::atomic<uint64_t> pwrite;

  std::mutex m{};
  std::condition_variable empty{};
  std::condition_variable full{};
  bool stoped;
};

template <typename T>
bool mpmc_queue<T>::pop(T& out) {
  std::unique_lock<std::mutex> lk(m);
  while (is_empty(pread)) {
    empty.wait(lk);
  }
  if (stoped) {
    return false;
  }
  auto item = std::move(buffer[pread % size]);
  pread++;
  lk.unlock();
  full.notify_one();

  out = std::move(item);
  return true;
}

template <typename T>
bool mpmc_queue<T>::push(T item) {
  std::unique_lock<std::mutex> lk(m);
  while (is_full(pwrite)) {
    full.wait(lk);
  }
  if (stoped) {
    return false;
  }
  buffer[pwrite % size] = std::move(item);

  pwrite++;
  lk.unlock();
  empty.notify_one();

  return true;
}

template <typename T>
bool mpmc_queue<T>::is_empty(unsigned long long current) const noexcept {
  if (stoped) {
    return false;
  }
  if (current >= pwrite) {
    return true;
  }
  return false;
}

template <typename T>
bool mpmc_queue<T>::is_full(unsigned long long current) const noexcept {
  if (stoped) {
    return false;
  }
  if (current >= (pread + size)) {
    return true;
  }
  return false;
}

template <typename T>
void mpmc_queue<T>::stop() {
  std::unique_lock<std::mutex> lk(m);
  stoped = true;
  lk.unlock();
  empty.notify_one();
  full.notify_one();
}

#endif
