#ifndef CPPPRATICE_STUDYOPENCV_UTILS_BASIC
#define CPPPRATICE_STUDYOPENCV_UTILS_BASIC

#include <iostream>
#include "opencv2/opencv.hpp"

void print_meta_mat(const cv::Mat& m) {
  std::cout << "rows: " << m.rows << std::endl;
  std::cout << "cols: " << m.cols << std::endl;

  cv::Size size = m.size();
  std::cout << "[列 * 行] size: " << size << std::endl;

  std::cout << "通道数 channels: " << m.channels() << std::endl;

  std::cout << "面积 total: " << m.total() << std::endl;

  std::cout << "维数 dims: " << m.dims << std::endl;
}

void print_mat(const cv::Mat& m) {
  print_meta_mat(m);

  for (int r = 0; r < m.rows; r++) {
    for (int c = 0; c < m.cols; c++) {
      std::cout << m.at<int>(r, c) << ", ";  //第r行第c列的值
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

#endif
