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

vector<uint8_t> read_image(string filename) {
  std::ifstream instream(filename, std::ios::in | std::ios::binary);
  std::vector<uint8_t> data((std::istreambuf_iterator<char>(instream)),
                            std::istreambuf_iterator<char>());
  return data;
}

void save_image(string filename, const vector<uint8_t>& data) {
  std::ofstream fout(filename);
  std::ostream_iterator<uint8_t> out_iter(fout);
  std::copy(data.cbegin(), data.cend(), out_iter);
}

void test1() {
  // 读取图片
  vector<uint8_t> data = read_image("input.jpg");
  cout << "len = " << data.size() << endl;

  // 将图片解码，转换为 cv::Mat 格式
  cv::Mat img = cv::imdecode(data, CV_LOAD_IMAGE_COLOR);

  // 对图片做处理
  cv::flip(img, img, -1);
  img.channels();

  // 将 cv::Mat 编码为 jpg 格式数据
  vector<uint8_t> out_buffer;
  cv::imencode(".jpg", img, out_buffer);

  // 保存图片
  save_image("output.jpg", out_buffer);
}

int main() {
  test1();
  return 0;
}
