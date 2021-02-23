/*
C语言中 lvalue 和 rvalue 定义：
An lvalue is an expression e that may appear on the left or on the right hand
side of an assignment, whereas an rvalue is an expression that can only appear
on the right hand side of an assignment.

C++语言中 lvalue 和 rvalue 定义：
An lvalue is an expression that refers to a memory location and allows us to
take the address of that memory location via the & operator. An rvalue is an
expression that is not an lvalue.
*/
#include <iostream>

void c_demo() {
  // a and b are both l-values
  int a = 42;
  int b = 43;

  a = b;
  b = a;
  a = a * b;

  // a * b is an rvalue
  int c = a * b;  // ok, rvalue on right hand side of assignment
  a* b = 42;      // error, rvalue on left hand side of assignment
}

void cpp_demo() {
  // lvalues:
  int i = 42;
  i = 43;       // ok, i is an lvalue
  int* p = &i;  // ok, i is an lvalue
  int& foo();
  foo() = 42;        // ok, foo() is an lvalue
  int* p1 = &foo();  // ok, foo() is an lvalue

  // rvalues:
  int foobar();
  int j = 0;
  j = foobar();         // ok, foobar() is an rvalue
  int* p2 = &foobar();  // error, cannot take the address of an rvalue
  j = 42;               // ok, 42 is an rvalue
}

int main() { return 0; }
