#include <iostream>

using namespace std;


class X {
 public:
  virtual ~X() {  }
};

class A {
 public:
  virtual ~A() {  }
};

class B: public A {
 public:
  virtual ~B() {  }
};

class C: public B {
 public:
  virtual ~C() {  }
};

class D: public C, public X {
 public:
  virtual ~D() {  }
};

/*
 * A <--- B <--- C <---+
 *                     | 
 *                     D
 *                     | 
 *               X <---+
 */

int main() {
  A* pa1 = new D;
  if (X* px1 = dynamic_cast<X*>(pa1)) {
    cout << "dynamic_cast 1 succeed" << endl;
  } else {
    cout << "dynamic_cast 1 failed" << endl;
  }

  D* pd2 = new D;
  if (A* pa2 = dynamic_cast<A*>(pd2)) {
    cout << "dynamic_cast 2 succeed" << endl;
  } else {
    cout << "dynamic_cast 2 fail" << endl;
  }

  /* This down cast will fail because 
   * the base class pointer pb3 does not pointer to a derived class D object. 
   */
  B* pb3 = new B;
  if (D* pd3 = dynamic_cast<D*>(pb3)) {
    cout << "dynamic_cast 3 succeed" << endl;
  } else {
    cout << "dynamic_cast 3 failed" << endl;
  }
  
  /* This down cast will success because the base class pointer pa4
   * bound to a pointer to the derived class C object. 
   */
  A* pa4 = new C;
  if (C* pc4 = dynamic_cast<C*>(pa4)) {
    cout << "dynamic_cast 4 succeed" << endl;
  } else {
    cout << "dynamic_cast 4 failed" << endl;
  }

  return 0;
}
