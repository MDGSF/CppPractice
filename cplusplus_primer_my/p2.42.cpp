#include <iostream>
#include <string>
#include "CSalesData.h"

int main() {
  CSalesData data1;
  CSalesData data2;

  double price = 0;
  std::cin >> data1.m_bookNo >> data1.m_unitSold >> price;
  data1.m_revenue = data1.m_unitSold * price;

  std::cin >> data2.m_bookNo >> data2.m_unitSold >> price;
  data2.m_revenue = data2.m_unitSold * price;

  if (data1.m_bookNo == data2.m_bookNo) {
    unsigned totalCnt = data1.m_unitSold + data2.m_unitSold;
    double totalRevenue = data1.m_revenue + data2.m_revenue;
    std::cout << data1.m_bookNo << " " << totalCnt << " " << totalRevenue
              << " ";
    if (totalCnt != 0) {
      std::cout << totalRevenue / totalCnt << std::endl;
    } else {
      std::cout << "(no sales)" << std::endl;
    }
  } else {
    std::cerr << "Data must refer to the same ISBN" << std::endl;
    return -1;
  }
  return 0;
}
