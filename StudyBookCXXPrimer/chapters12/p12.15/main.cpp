#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <fstream>  // ifstream
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>  // unique_ptr, shared_ptr, weak_ptr
#include <set>
#include <sstream>  // istringstream
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct Connection {
  int id;
};

Connection new_connection(int id) {
  Connection conn;
  conn.id = id;
  return conn;
}

void end_connection(Connection conn) {
  printf("end connection: %d\n", conn.id);
}

void test() {
  Connection conn = new_connection(123);
  shared_ptr<Connection> p(&conn,
                           [](Connection* conn) { end_connection(*conn); });
}

int main() {
  cout << "hello world!" << endl;
  test();
  return 0;
}
