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
  // 矩阵相加，矩阵类型必须相同
  // 超过uchar的大小，会取最大值255
  Mat src1 = (Mat_<uchar>(2, 3) << 23, 123, 90, 100, 250, 0);
  Mat src2 = (Mat_<uchar>(2, 3) << 125, 150, 60, 100, 10, 40);
  Mat dst = src1 + src2;

  cout << src1 << endl << endl;
  cout << src2 << endl << endl;
  cout << dst << endl << endl;

  // 矩阵和数值相加，会给矩阵中的每个值都加上
  // float 类型会截断为uchar
  float value = 100;
  cv::Mat dst1 = src1 + value;
  cout << dst1 << endl << endl;

  return 0;
}
