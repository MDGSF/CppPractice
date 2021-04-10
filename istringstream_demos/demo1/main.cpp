#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  string line = "1615445777 927215 CAN0 0x60b 5e 62 f3 c5 72 a0 c1 bf";

  uint64_t sec, us;
  string type;
  string str_can_id;
  string str_can_data_0;
  string str_can_data_1;
  string str_can_data_2;
  string str_can_data_3;
  string str_can_data_4;
  string str_can_data_5;
  string str_can_data_6;
  string str_can_data_7;

  istringstream stream(line);
  stream >> sec >> us >> type >> str_can_id >> str_can_data_0 >>
      str_can_data_1 >> str_can_data_2 >> str_can_data_3 >> str_can_data_4 >>
      str_can_data_5 >> str_can_data_6 >> str_can_data_7;

  int can_id = stoi(str_can_id, nullptr, 16);
  int can_data_0 = stoi(str_can_data_0, nullptr, 16);
  int can_data_1 = stoi(str_can_data_1, nullptr, 16);
  int can_data_2 = stoi(str_can_data_2, nullptr, 16);
  int can_data_3 = stoi(str_can_data_3, nullptr, 16);
  int can_data_4 = stoi(str_can_data_4, nullptr, 16);
  int can_data_5 = stoi(str_can_data_5, nullptr, 16);
  int can_data_6 = stoi(str_can_data_6, nullptr, 16);
  int can_data_7 = stoi(str_can_data_7, nullptr, 16);

  cout << line << endl;
  cout << sec << " " << us << " " << type << endl;
  cout << "str_can_id = " << str_can_id << endl;
  cout << "str_can_data_0 = " << str_can_data_0 << endl;
  cout << "str_can_data_1 = " << str_can_data_1 << endl;
  cout << "str_can_data_2 = " << str_can_data_2 << endl;
  cout << "str_can_data_3 = " << str_can_data_3 << endl;
  cout << "str_can_data_4 = " << str_can_data_4 << endl;
  cout << "str_can_data_5 = " << str_can_data_5 << endl;
  cout << "str_can_data_6 = " << str_can_data_6 << endl;
  cout << "str_can_data_7 = " << str_can_data_7 << endl;

  cout << "can_id = " << can_id << endl;
  cout << "can_data_0 = " << can_data_0 << endl;
  cout << "can_data_1 = " << can_data_1 << endl;
  cout << "can_data_2 = " << can_data_2 << endl;
  cout << "can_data_3 = " << can_data_3 << endl;
  cout << "can_data_4 = " << can_data_4 << endl;
  cout << "can_data_5 = " << can_data_5 << endl;
  cout << "can_data_6 = " << can_data_6 << endl;
  cout << "can_data_7 = " << can_data_7 << endl;



  return 0;
}

