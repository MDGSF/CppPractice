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
  /*
  3行2列的矩阵
  11 12
  33 43
  51 16
  */
  cv::Mat m = (cv::Mat_<int>(3, 2) << 11, 12, 33, 43, 51, 16);
  cout << "行 rows: " << m.rows << endl;
  cout << "列 cols: " << m.cols << endl;

  // 这个输出的行列是颠倒的，输出[2 * 3]表示3行2列
  cv::Size size = m.size();
  cout << "[列 * 行] size: " << size << endl;

  // 输出通道数
  cout << "通道数 channels: " << m.channels() << endl;

  // 返回值是矩阵的行数乘以列数，即面积。
  // 注意和通道数无关，返回的不是矩阵中数据的个数
  cout << "面积 total: " << m.total() << endl;

  // dims代表矩阵的维数，显然对于单通道矩阵来说就是一个二维矩阵，
  // 对于多通道矩阵来说就是一个三维矩阵
  cout << "维数 dims: " << m.dims << endl;

  // 输出矩阵
  for (int r = 0; r < m.rows; r++) {
    for (int c = 0; c < m.cols; c++) {
      cout << m.at<int>(r, c) << ", ";  //第r行第c列的值
    }
    cout << endl;
  }
  cout << endl;

  // 输出矩阵
  for (int r = 0; r < m.rows; r++) {
    for (int c = 0; c < m.cols; c++) {
      // Point(col, row) 行列是颠倒的
      cout << m.at<int>(cv::Point(c, r)) << ", ";
    }
    cout << endl;
  }
  cout << endl;

  // 输出矩阵
  for (int r = 0; r < m.rows; r++) {
    // 得到第r行行首的地址
    const int* ptr = m.ptr<int>(r);

    // 打印第r行的所有值
    for (int c = 0; c < m.cols; c++) {
      cout << ptr[c] << ", ";
    }
    cout << endl;
  }
  cout << endl;

  // 每一行的所有值存储在连续的内存区域中，行与行之间可能会有间隔，
  // 如果isContinuous返回值为true，则代表行与行之间也是连续存储的，
  // 即所有的值都是连续存储的
  if (m.isContinuous()) {
    cout << "m is continuous" << endl;
    int* ptr = m.ptr<int>(0);
    for (int n = 0; n < m.rows * m.cols; n++) {
      cout << ptr[n] << ", ";
    }
    cout << endl;
  } else {
    cout << "m is not continuous" << endl;
  }
  cout << endl;

  // m.data 指向第一个数值的指针
  // m.step[0] 表示一行所占的字节数，包括行与行之间的间隔
  // m.step[1] 表示每一个数值所占的字节数
  for (int r = 0; r < m.rows; r++) {
    for (int c = 0; c < m.cols; c++) {
      cout << *((int*)(m.data + m.step[0] * r + c * m.step[1])) << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
