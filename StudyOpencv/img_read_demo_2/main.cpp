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

#include "basic.h"
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
  cv::Mat img = cv::imread(argv[1], IMREAD_ANYCOLOR);
  if (!img.data) {
    return -1;
  }

  //显示彩色图像
  imshow("BGR", img);  //分离通道

  vector<Mat> planes;

  // 分离通道
  // 每一个像素的向量不是按照R、G、B分量排列的，
  // 而是按照B、G、R顺序排列的，所以通过split函数分离通道后，
  // 先后得到的是B、G、R通道。
  split(img, planes);

  imshow("B", planes[0]);  //显示 B 通道

  imshow("G", planes[1]);  //显示 G 通道

  imshow("R", planes[2]);  //显示 R 通道

  waitKey(0);

  return 0;
}
