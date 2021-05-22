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
在OpenCV中最核心的类是Mat，它是Matrix的缩写，代表矩阵或者数组的意思，该类的声明在头文件opencv2\core\core.hpp中，所以使用Mat类时要引入该头文件。构造Mat对象相当于构造了一个矩阵（数组），需要四个基本要素：行数（高）、列数（宽）、通道数及其数据类型，所以Mat类的构造函数如下：
    Mat(int rows, int cols, int type)
其中，rows代表矩阵的行数，cols代表矩阵的列数，type代表类型，包括通道数及其数据类型，可以设置为CV_8UC(n)、CV_8SC(n)、CV_16SC(n)、CV_16UC(n)、CV_32SC(n)、CV_32FC(n)、CV_64FC(n)，其中8U、8S、16S、16U、32S、32F、64F前面的数字代表Mat中每一个数值所占的bit数，而1byte=8bit，所以，32F就是占4字节的float类型，64F是占8字节的doule类型，32S是占4字节的int类型，8U是占1字节的uchar类型，其他的类似；C(n)代表通道数，当n=1
时，即构造单通道矩阵或称二维矩阵，当n>1
时，即构造多通道矩阵即三维矩阵，直观上就是n
个二维矩阵组成的三维矩阵。这里所说的单通道矩阵和二维ndarray是等价的，而多通道矩阵和三维ndarray是等价的。对于Mat构造函数也可以采用以下形式：
    Mat(Size(int cols, int rows), int type)
其中使用了OpenCV的Size类，该类一般用来存储矩阵的列数和行数。需要注意的是， Size的第一个元素是矩阵的列数（宽），第二个元素是矩阵的行数（高），即先存宽，再存高，与ndarray的shape相反。
*/

int main(int argc, char* argv[]) {
  // 构造2行3列的矩阵，32bit float 类型，通道数为1
  cv::Mat m1 = cv::Mat(2, 3, CV_32FC(1));

  // 构造2行3列的矩阵，32bit float 类型，通道数为1
  cv::Mat m2 = cv::Mat(cv::Size(3, 2), CV_32FC(1));

  // 构造2行3列的矩阵，32bit float 类型，通道数为1
  // CV_32FC1 等价于 CV_32FC(1)
  cv::Mat m3;
  m3.create(2, 3, CV_32FC1);

  // 构造2行3列全是1的矩阵，32bit float 类型，通道数为1
  cv::Mat m4 = cv::Mat::ones(2, 3, CV_32FC1);

  // 构造2行3列全是0的矩阵，32bit float 类型，通道数为1
  cv::Mat m5 = cv::Mat::zeros(2, 3, CV_32FC1);

  // 构造2行3列的矩阵，int 类型，通道数为1
  cv::Mat m6 = (cv::Mat_<int>(2, 3) << 1, 2, 3, 4, 5, 6);
  return 0;
}
