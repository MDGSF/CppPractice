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
  // 矩阵相减，矩阵类型必须相同
  // 超过uchar的大小，会取最大值255，会取最小值0
  Mat src1 = (Mat_<uchar>(2, 3) << 23, 123, 90, 100, 250, 0);
  Mat src2 = (Mat_<uchar>(2, 3) << 125, 150, 60, 100, 10, 40);
  Mat dst = src1 - src2;

  cout << src1 << endl << endl;
  cout << src2 << endl << endl;
  cout << dst << endl << endl;

  cv::Mat dst2;
  cv::subtract(src1, src2, dst2, cv::Mat(), CV_64FC1);
  cout << dst2 << endl << endl;

  return 0;
}
