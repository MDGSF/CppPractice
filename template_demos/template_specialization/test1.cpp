// 特化，就是泛型特殊化处理，泛型用来处理 80% 的情况，
// 还有一些特殊情况也许需要特殊处理

#include <iostream>

using namespace std;

// a generic sort function
template <class T>
void sort(T arr[], int size) {
  // 快速排序
}

// Template Specialization: A function
// specialized for char data type
template <>
void sort<char>(char arr[], int size) {
  // 为 char 类型单独实现计数排序
}

int main() {
  return 0;
}
