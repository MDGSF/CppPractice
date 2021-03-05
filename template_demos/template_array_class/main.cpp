#include <iostream>

using namespace std;

template <typename T>
class Array {
 public:
  Array(T arr[], int size);
  void print();

 private:
  T *m_ptr;
  int m_size;
};

template <typename T>
Array<T>::Array(T arr[], int size) {
  m_ptr = new T[size];
  m_size = size;
  for (int i = 0; i < size; i++) {
    m_ptr[i] = arr[i];
  }
}

template <typename T>
void Array<T>::print() {
  for (int i = 0; i < m_size; i++) {
    cout << m_ptr[i] << " ";
  }
  cout << endl;
}

int main() {
  int a[5] = {1, 2, 3, 4, 5};
  Array<int> arr(a, 5);
  arr.print();
  return 0;
}
