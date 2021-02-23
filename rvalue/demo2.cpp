#include <iostream>

using namespace std;

class Demo {
 public:
  Demo() = default;   // 明确告诉编译器，使用默认实现
  ~Demo() = default;  // 明确告诉编译器，使用默认实现

  // 拷贝构造函数
  Demo(const Demo& rhs) {
    printf("Demo(const Demo&)\n");
    this->m_id = rhs.m_id;
  }

  // 拷贝赋值函数
  Demo& operator=(const Demo& rhs) {
    printf("Demo& operator=(const Demo&)\n");
    this->m_id = rhs.m_id;
    return *this;
  }

  // 转移构造函数
  Demo(Demo&& rhs) {
    printf("Demo(Demo&& rhs)\n");
    this->m_id = rhs.m_id;
  }

  // 转移赋值函数
  Demo& operator=(Demo&& rhs) {
    printf("Demo& operator=(Demo&& rhs)\n");
    this->m_id = rhs.m_id;
    return *this;
  }

  explicit Demo(int id) : m_id(id) {}

  int get_id() { return m_id; }

 private:
  int m_id = 0;
};

void test1() {
  Demo a(123);
  Demo b = std::move(a);
  cout << a.get_id() << endl;
  cout << b.get_id() << endl;
}

// Things that are declared as rvalue reference can be lvalues or rvalues.
// The distinguishing criterion is: if it has a name, then it is an lvalue.
// Otherwise, it is an rvalue.
void foo(Demo&& x) {
  Demo another_x = x; // call Demo(const Demo& rhs)
}

Demo&& goo() {
  return std::move(Demo(456));
}

int main() {
  // test1();

  Demo a(123);
  foo(std::move(a));

  // goo() 的返回值没有名字，所以调用转移构造函数
  // call Demo(Demo&& rhs)
  Demo b = goo();

  return 0;
}
