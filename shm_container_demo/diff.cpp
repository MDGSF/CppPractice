#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("usage: diff file1 file2\n");
    exit(0);
  }

  ifstream file1;
  file1.open(argv[1]);

  ifstream file2;
  file2.open(argv[2]);

  std::string line1;
  std::string line2;

  uint64_t lineCount1 = 0;
  uint64_t lineCount2 = 0;

  while (true) {
    bool bFile1ExistsLine = false;
    if (std::getline(file1, line1)) {
      bFile1ExistsLine = true;
      lineCount1++;
    }

    bool bFile2ExistsLine = false;
    if (std::getline(file2, line2)) {
      bFile2ExistsLine = true;
      lineCount2++;
    }

    if (!bFile1ExistsLine && !bFile2ExistsLine) {
      break;
    }

    if (bFile1ExistsLine && bFile2ExistsLine) {
      if (line1 != line2) {
        cout << "lineCount1 = "<< lineCount1 << std::endl;
        cout << "lineCount2 = "<< lineCount2 << std::endl;
        cout << "line1 = " << line1 << std::endl;
        cout << "line2 = " << line2 << std::endl;
        exit(0);
      }
    }
  }

  cout << "lineCount1 = " << lineCount1 << endl;
  cout << "lineCount2 = " << lineCount2 << endl;

  return 0;
}
