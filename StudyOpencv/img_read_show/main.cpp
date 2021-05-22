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
  cv::Mat img = cv::imread(argv[1], IMREAD_ANYCOLOR);
  if (!img.data) {
    return -1;
  }
  cv::imshow("image", img);
  cv::waitKey(0);
  return 0;
}
