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
OpenCV为向量类取的别名，

typedef Vec<uchar, 2> Vec2b;
typedef Vec<uchar, 3> Vec3b;
typedef Vec<uchar, 4> Vec4b;

typedef Vec<short, 2> Vec2s;
typedef Vec<short, 3> Vec3s;
typedef Vec<short, 4> Vec4s;

typedef Vec<ushort, 2> Vec2w;
typedef Vec<ushort, 3> Vec3w;
typedef Vec<ushort, 4> Vec4w;

typedef Vec<int, 2> Vec2i;
typedef Vec<int, 3> Vec3i;
typedef Vec<int, 4> Vec4i;
typedef Vec<int, 6> Vec6i;
typedef Vec<int, 8> Vec8i;

typedef Vec<float, 2> Vec2f;
typedef Vec<float, 3> Vec3f;
typedef Vec<float, 4> Vec4f;
typedef Vec<float, 6> Vec6f;

typedef Vec<double, 2> Vec2d;
typedef Vec<double, 3> Vec3d;
typedef Vec<double, 4> Vec4d;
typedef Vec<double, 6> Vec6d;

*/

int main(int argc, char* argv[]) {
  // 构造一个3行1列的列向量
  cv::Vec<int, 3> vi(21, 32, 14);
  cout << "rows: " << vi.rows << endl;  // rows: 3
  cout << "cols: " << vi.cols << endl;  // cols: 1

  // 访问向量中的值，可以使用[]或()操作符
  cout << "vi[0]: " << vi[0] << endl;  // 21
  cout << "vi(1): " << vi(1) << endl;  // 32

  // 单通道矩阵的每一个元素都是一个数值
  // 多通道矩阵的每一个元素都可以看作一个向量。
  // 构造一个2行2列的float类型的3通道矩阵
  cv::Mat mm =
      (cv::Mat_<cv::Vec3f>(2, 2) << cv::Vec3f(1, 11, 21), cv::Vec3f(2, 12, 22),
       cv::Vec3f(3, 13, 23), cv::Vec3f(4, 14, 24));

  for (int r = 0; r < mm.rows; r++) {
    for (int c = 0; c < mm.cols; c++) {
      cout << mm.at<Vec3f>(r, c) << " ";
    }
    cout << endl;
  }
  cout << endl;

  for (int r = 0; r < mm.rows; r++) {
    // 得到第r行行首的地址
    cv::Vec3f* ptr = mm.ptr<cv::Vec3f>(r);
    for (int c = 0; c < mm.cols; c++) {
      cout << ptr[c] << " ";
    }
    cout << endl;
  }
  cout << endl;

  if (mm.isContinuous()) {
    cout << "mm is continuous" << endl;
    cv::Vec3f* ptr = mm.ptr<cv::Vec3f>(0);
    for (int n = 0; n < mm.rows * mm.cols; n++) {
      cout << ptr[n] << ", ";
    }
    cout << endl;
  } else {
    cout << "mm is not continuous" << endl;
  }
  cout << endl;

  // elemSize1() 表示每个数值所占的字节数
  // step[1] 和 elemSize() 相等，表示每个元素所占的字节数，
  // step[1] == elemSize()
  // step[1] = elemSize1() * channels()
  // step[0] 表示每一行所占字节数，包括行与行之间的间隔
  for (int r = 0; r < mm.rows; ++r) {
    for (int c = 0; c < mm.cols; ++c) {
      // 得到指向每个元素的指针
      cv::Vec3f* ptr = (cv::Vec3f*)(mm.data + r * mm.step[0] + c * mm.step[1]);
      cout << *ptr << " ";
    }
    cout << endl;
  }
  cout << endl;

  // 分离通道
  // 将3通道矩阵mm分离为3个单通道矩阵
  vector<cv::Mat> planes;
  cv::split(mm, planes);
  for (size_t i = 0; i < planes.size(); ++i) {
    const cv::Mat& m = planes[i];
    cout << m << endl;
  }
  cout << endl;

  // 合并通道
  // 将多个单通道矩阵合并
  cv::Mat plane0 = (cv::Mat_<int>(2, 2) << 1, 2, 3, 4);
  cv::Mat plane1 = (cv::Mat_<int>(2, 2) << 5, 6, 7, 8);
  cv::Mat plane2 = (cv::Mat_<int>(2, 2) << 9, 10, 11, 12);
  vector<cv::Mat> plane;
  plane.push_back(plane0);
  plane.push_back(plane1);
  plane.push_back(plane2);
  cv::Mat mat;
  cv::merge(plane, mat);
  cout << mat << endl;

  return 0;
}
