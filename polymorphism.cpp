#include <iostream>

using namespace std;


class A {
 public:
  virtual void Test() {
    cout << "A test()" << endl;
  }
};

class B: public A {
 public:
  void func() {
    Test();
  }
  virtual void Test() {
    cout << "B test()" << endl;
  }
};

class C: public B {
 public:
  virtual void Test() {
    cout << "C test()" << endl;
  }
};


int main() {
  C c;
  ((B*)(&c))->func();
  ((B)c).func();
} 
