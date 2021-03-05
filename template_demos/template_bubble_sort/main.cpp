#include <iostream>

using namespace std;

template <class T>
void bubble_sort(T a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = n - 1; j > i; j--) {
      if (a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
      }
    }
  }
}

int main() {
  int a[5] = {10, 50, 20, 30, 40};
  int n = sizeof(a) / sizeof(a[0]);
  bubble_sort<int>(a, n);
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
