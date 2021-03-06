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

/*
Mat imread(const string\& filename, int flags=1)

flags 取值
IMREAD_COLOR 彩色图像
IMREAD_GRAYSCALE 灰度图像
IMREAD_ANYCOLOR 任意图像
*/

int main(int argc, char* argv[]) {
  // flags=IMREAD_GRAYSCALE，输入彩色图像，会进行灰度化处理
  // cv::Mat img = cv::imread(argv[1], IMREAD_GRAYSCALE);
  cv::Mat img = cv::imread(argv[1], IMREAD_ANYCOLOR);
  if (!img.data) {
    return -1;
  }
  cv::imshow("image", img);
  cv::waitKey(0);
  return 0;
}
