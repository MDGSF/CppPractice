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
  // 最后一个参数指定了输出矩阵的类型
  // 如果最后一个参数不填，使用默认值-1，那么src1和src2的类型必须相同
  cv::Mat src1 = (cv::Mat_<uchar>(2, 3) << 23, 123, 90, 100, 250, 0);
  cv::Mat src2 = (cv::Mat_<float>(2, 3) << 125, 150, 60, 100, 10, 40);
  cv::Mat dst;
  cv::add(src1, src2, dst, cv::Mat(), CV_64FC1);

  cout << src1 << endl << endl;
  cout << src2 << endl << endl;
  cout << dst << endl << endl;
  return 0;
}
