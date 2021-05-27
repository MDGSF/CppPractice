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
  cv::Mat matrix = (cv::Mat_<int>(5, 5) << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
                    12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25);
  cout << matrix << endl << endl;

  // roi1, roi2, roi3 指向原矩阵，可以使用 clone 或 copyTo 来拷贝
  cv::Mat roi1 =
      matrix(Rect(Point(2, 1), Point(4, 3)));  //左上角的坐标，右下角的坐标
  cv::Mat roi2 = matrix(Rect(2, 1, 2, 2));               // x, y，宽度，高度
  cv::Mat roi3 = matrix(Rect(Point(2, 1), Size(2, 2)));  //左上角的坐标，尺寸

  cout << roi1 << endl << endl;
  cout << roi2 << endl << endl;
  cout << roi3 << endl << endl;

  return 0;
}
