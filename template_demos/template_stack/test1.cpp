#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
class Stack {
 public:
  void push(T const &);
  void pop();
  T top() const;
  bool empty() const { return m_elems.empty(); }

 private:
  vector<T> m_elems;
};

template <class T>
void Stack<T>::push(T const &elem) {
  m_elems.push_back(elem);
}

template <class T>
void Stack<T>::pop() {
  if (m_elems.empty()) {
    throw out_of_range("Stack<T>::pop empty stack");
  }
  m_elems.pop_back();
}

template <class T>
T Stack<T>::top() const {
  if (m_elems.empty()) {
    throw out_of_range("Stack<T>::pop empty stack");
  }
  return m_elems.back();
}

int main() try {
  Stack<int> int_stack;
  Stack<string> string_stack;

  int_stack.push(7);
  cout << int_stack.top() << endl;

  string_stack.push("hello");
  cout << string_stack.top() << endl;

  string_stack.pop();
  string_stack.pop();

  return 0;
} catch (std::exception &e) {
  cerr << e.what() << endl;
}
