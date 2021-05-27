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
  // 两个向量相加
  Vec3f v1 = Vec3f(1, 2, 3);
  Vec3f v2 = Vec3f(10, 1, 12);
  Vec3f v = v1 + v2;
  cout << v1 << endl << endl;
  cout << v2 << endl << endl;
  cout << v << endl << endl;  // [11, 3, 15]
  return 0;
}
