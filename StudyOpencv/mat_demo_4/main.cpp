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
  // 构造2行3列的矩阵，int 类型，通道数为1
  cv::Mat m = (cv::Mat_<int>(2, 3) << 1, 2, 3, 4, 5, 6);
  cout << m << endl << endl;

  // 获取矩阵的第1行，返回值还是矩阵
  cv::Mat mr = m.row(1);
  cout << mr << endl << endl;

  // 获取矩阵的第0列，返回值还是矩阵
  cv::Mat mc = m.col(0);
  cout << mc << endl << endl;

  cv::Mat matrix = (cv::Mat_<int>(5, 5) << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
                    12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25);
  cout << matrix << endl << endl;

  // cv::Range(start, end) 是一个 [start, end) 的整数序列
  // 获取matrix的第2、3行
  // cv::Mat r_range = matrix.rowRange(2, 4); 函数重载，等价于下一行代码
  cv::Mat r_range = matrix.rowRange(cv::Range(2, 4));
  for (int r = 0; r < r_range.rows; ++r) {
    for (int c = 0; c < r_range.cols; ++c) {
      cout << r_range.at<int>(r, c) << " ";
    }
    cout << endl;
  }
  cout << endl;

  // 获取matrix的第1、2列
  cv::Mat c_range = matrix.colRange(1, 3);
  for (int r = 0; r < c_range.rows; ++r) {
    for (int c = 0; c < c_range.cols; ++c) {
      cout << c_range.at<int>(r, c) << " ";
    }
    cout << endl;
  }
  cout << endl;

  // rowRange 和 colRange 的返回值是指向原矩阵的，修改会影响到原矩阵
  // r_range.at<int>(0, 0) = 10000;
  // cout << matrix << endl << endl;

  // 使用 clone 或 copyTo 来拷贝矩阵，可以防止原矩阵被修改。
  cv::Mat rmat1 = matrix.rowRange(2, 4).clone();

  cv::Mat rmat2;
  matrix.rowRange(2, 4).copyTo(rmat2);

  return 0;
}
