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
  // 矩阵点乘即两个矩阵对应位置的数值相乘。
  // 超过uchar的大小，会取最大值255，会取最小值0
  Mat src1 = (Mat_<uchar>(2, 3) << 23, 123, 90, 100, 250, 0);
  Mat src2 = (Mat_<uchar>(2, 3) << 125, 150, 60, 100, 10, 40);
  Mat dst = src1.mul(src2);

  cout << src1 << endl << endl;
  cout << src2 << endl << endl;
  cout << dst << endl << endl;

  // void multiply(InputArray src1, InputArray src2, OutputArray dst,
  //               double scale =1, int dtype=-1 )
  //
  // dst = scale * src1 * src2
  cv::Mat dst2;
  cv::multiply(src1, src2, dst2, 1.0, CV_32FC1);
  //cout << dst2 << endl << endl;
  for (int r = 0; r < dst2.rows; ++r) {
    for (int c = 0; c < dst2.cols; ++c) {
      cout << dst2.at<float>(r, c) << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
