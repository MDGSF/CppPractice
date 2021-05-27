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
  // 点除运算与点乘运算类似，是两个矩阵对应位置的数值相除。
  // 超过uchar的大小，会取最大值255，会取最小值0
  Mat src1 = (Mat_<uchar>(2, 3) << 23, 123, 90, 100, 250, 0);
  Mat src2 = (Mat_<uchar>(2, 3) << 125, 150, 60, 100, 10, 40);
  Mat dst = src2 / src1;

  cout << src1 << endl << endl;
  cout << src2 << endl << endl;
  cout << dst << endl << endl;

  // divide();

  return 0;
}
