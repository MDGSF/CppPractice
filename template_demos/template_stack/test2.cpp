#include <iostream>

using namespace std;

template <class T>
class Stack {
 public:
  Stack(int size = 10);
  ~Stack() {
    if (m_ptr != nullptr) {
      delete[] m_ptr;
    }
  }

  int push(const T &);
  int pop(T &);
  bool is_empty() const { return m_top == -1; }
  bool is_full() const { return m_top == m_size - 1; }

 private:
  int m_size = 0;
  int m_top = -1;
  T *m_ptr = nullptr;
};

template <class T>
Stack<T>::Stack(int size) {
  m_size = size > 0 && size < 1000 ? size : 10;
  m_top = -1;
  m_ptr = new T[m_size];
}

template <class T>
int Stack<T>::push(const T &item) {
  if (is_full()) {
    return -1;
  }
  m_ptr[++m_top] = item;
  return 0;
}

template <class T>
int Stack<T>::pop(T &item) {
  if (is_empty()) {
    return -1;
  }
  item = m_ptr[m_top--];
  return 0;
}

int main() {
  typedef Stack<float> TFloatStack;
  using TIntStack = Stack<int>;

  TFloatStack fs(5);
  TIntStack Is(7);
  return 0;
}
