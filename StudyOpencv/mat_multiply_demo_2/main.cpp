#include <algorithm>
#include <fstream>     // ifstream
#include <functional>  // function object, bind
#include <iostream>    // cin, cout, cerr
#include <iterator>
#include <list>
#include <map>
#include <memory>  // unique_ptr, shared_ptr, weak_ptr
#include <set>
#include <sstream>  // istringstream
#include <string>
#include <utility>
#include <vector>

#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
  // 矩阵乘法，就是大学线性代数里学的
  Mat src1 = (Mat_<float>(2, 3) << 1, 2, 3, 4, 5, 6);
  Mat src2 = (Mat_<float>(3, 2) << 6, 5, 4, 3, 2, 1);
  Mat dst1 = src1 * src2;

  cout << src1 << endl << endl;
  cout << src2 << endl << endl;
  cout << dst1 << endl << endl;

  // 双通道矩阵，被当做了复数矩阵相乘
  Mat src3 = (Mat_<Vec2f>(2, 1) << Vec2f(1, 2), Vec2f(3, 4));
  Mat src4 = (Mat_<Vec2f>(1, 2) << Vec2f(10, 20), Vec2f(5, 15));
  Mat dst2 = src3 * src4;

  cout << src3 << endl << endl;
  cout << src4 << endl << endl;
  cout << dst2 << endl << endl;

  /*
  gemm是generalized matrix multiplication的缩号，指通常的矩阵乘法，而不是矩阵点乘，
  void gemm(InputArray src1, InputArray src2, double alpha,
            InputArray src3, double beta, OutputArray dst, int flags=0)
  下面的src1(T)，src2(T)，src3(T)表示转置矩阵
  if flags == 0:
    dst = alpha * src1 * src2 + beta * src3
  elif flags == GEMM_1_T:
    dst = alpha * src1(T) * src2 + beta * src3
  elif flags == GEMM_2_T:
    dst = alpha * src1 * src2(T) + beta * src3
  elif flags == GEMM_3_T:
    dst = alpha * src1 * src2 + beta * src3(T)
  */

  Mat dst3;
  gemm(src3, src4, 1, NULL, 0, dst3, 0);
  cout << dst3 << endl << endl;

  return 0;
}
