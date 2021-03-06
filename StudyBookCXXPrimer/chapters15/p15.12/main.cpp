/*
1. Compare `f1()` and `f6()`. We know that `override` and `final` is indepent sematically.

  - `override` means the function is overriding a virtual function in its base class. See `f1()` and `f3()`.
  - `final` means the function cannot be overrided by its derived class. (But the function itself need not override a base class virtual function.) See `f6()` and `f4()`.

2. Compare `f2()` and `f3()`. We know that if a member function is declared without `virtual` and with `final`, it means that it already override a virtual function in base class. In this case, the key word `override` is redundant.

3. Compare `f4()` and `f5()`. We know that if a member function is declared with `virtual`and if it is not the *first* virtual function in inheritance hierarchy, then we should use `override` to specify the override relationship. Otherwise, we may accidentally add new virtual function in derived class.

4. Compare `f1()` and `f7()`. We know that any member function, not just virtual ones, can be overridden in derived class. What `virtual` specifies is *polymorphism*, which means the decision as to which function to run is delayed until run time instead of compile time. (This should be avoid in practice.)

5. Compare `f7()` and `f8()`. We know that we can even override a base class function and make it a new virtual one. (Which means any member function `f8()` of class derived from `D` will be virtual.) (This should be avoid in practice too.)

6. Compare `f7()` and `f9()`. We know that `override` can help us find the error when we want to override a virtual function in derived class while forgot to add key word `virtual` in base class.

**In conclusion**, the best practice in my own view is:

  - *only* use `virtual` in declaration of the *first* virtual function in base class;
  - always use `override` to specify override virtual function in derived class, unless `final` is also specified.
*/

#include <iostream>
using std::cout;
using std::endl;

struct B {
  virtual void f1() { cout << "B::f1() "; }
  virtual void f2() { cout << "B::f2() "; }
  virtual void f3() { cout << "B::f3() "; }
  virtual void f6() final { cout << "B::f6() "; }
  void f7() { cout << "B::f7() "; }
  void f8() { cout << "B::f8() "; }
  void f9() { cout << "B::f9() "; }
};

struct D : B {
  void f1() override { cout << "D::f1() "; }
  void f2() final { cout << "D::f2() "; }
  void f3() override final { cout << "D::f3() "; }  // need not have override
  // should have override, otherwise add new virtual function
  virtual void f4() final { cout << "D::f4() "; }
  // virtual void f5() override final;  // Error, no virtual function in base
  // class void f6(); // Error, override a final virtual function
  void f7() { cout << "D::f7() "; }
  virtual void f8() { cout << "D::f8() "; }
  // void f9() override;  // Error, override a nonvirtual function
};

int main() {
  B b;
  D d;
  B *bp = &b, *bd = &d;
  D *dp = &d;
  bp->f1();
  bp->f2();
  bp->f3();
  bp->f6();
  bp->f7();
  bp->f8();
  bp->f9();
  cout << endl;
  bd->f1();
  bd->f2();
  bd->f3();
  bd->f6();
  bd->f7();
  bd->f8();
  bd->f9();
  cout << endl;
  dp->f1();
  dp->f2();
  dp->f3();
  dp->f6();
  dp->f7();
  dp->f8();
  dp->f9();
  cout << endl;
  return 0;
}

