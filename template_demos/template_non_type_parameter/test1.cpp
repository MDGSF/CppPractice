#include <iostream>

using namespace std;

// max 这个不是类型的参数只能是常量
template <class T, int max>
int arr_min(T arr[], int n) {
  int result = max;
  for (int i = 0; i < n; i++) {
    if (arr[i] < result) {
      result = arr[i];
    }
  }
  return result;
}

int main() {
  int arr1[] = {10, 20, 15, 12};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);

  char arr2[] = {1, 2, 3};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);

  cout << arr_min<int, 1000>(arr1, n1) << endl;
  cout << arr_min<char, 256>(arr2, n2) << endl;
  return 0;
}
