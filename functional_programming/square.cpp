#include <stdio.h>

int main() {
  auto square = [](double x) { return x * x; };
  double square_five = square(5.0);
  printf("square_five = %lf\n", square_five);
  return 0;
}
