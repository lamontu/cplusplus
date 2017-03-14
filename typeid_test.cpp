#include <iostream>
#include <complex>

using namespace std;

class Base {  };
class Derived: public Base {  };

class VBase { virtual void f() {  } };
class VDerived: public VBase {  };

int main() {
  cout << typeid(short).name() << endl
       << typeid(unsigned short).name() << endl 
       << typeid(int).name() << endl
       << typeid(unsigned).name() << endl
       << typeid(long).name() << endl
       << typeid(unsigned long).name() << endl
       << typeid(char).name() << endl
       << typeid(unsigned char).name() << endl
       << typeid(float).name() << endl
       << typeid(double).name() << endl<< endl;
  cout << typeid(string).name() << endl
       << typeid(complex<double>).name() << endl << endl;
  cout << typeid(type_info).name() << endl;

  cout << "------------------------------------" << endl;

  // apply typeid in class without virtual function 
  Base b1, *pb1;
  pb1 = nullptr;
  Derived d1, *pd1;
  pd1 = &d1;
  cout << typeid(Base).name() << endl
       << typeid(b1).name() << endl
       << typeid(pb1).name() << endl
       << typeid(Derived).name() << endl
       << typeid(d1).name() << endl
       << typeid(pd1).name() << endl << endl;
 
  Base b2, *pb2;
  Derived d2, *pd2;
  pb2 = dynamic_cast<Base*>(new Derived);
  Base& rb2 = d2;
  Base* pbd2 = &d2;
  cout << typeid(b2).name() << endl
       << typeid(rb2).name() << endl
       << typeid(pbd2).name() << endl
       << typeid(*pbd2).name() << endl;

  cout << "------------------------------------" << endl;

  // apply typeid in class with virtual function
  VBase vb1, *vpb1;
  vpb1 = nullptr;
  VDerived vd1, *vpd1;
  vpd1 = &vd1;
  cout << typeid(VBase).name() << endl
       << typeid(vb1).name() << endl
       << typeid(vpb1).name() << endl
       << typeid(VDerived).name() << endl
       << typeid(vd1).name() << endl
       << typeid(vpd1).name() << endl << endl;
 
  VBase vb2, *vpb2;
  VDerived vd2, *vpd2;
  vpb2 = dynamic_cast<VBase*>(new VDerived);
  VBase& vrb2 = vd2;
  VBase* vpbd2 = &vd2;
  cout << typeid(vb2).name() << endl
       << typeid(vrb2).name() << endl  //  Different, VDerived class 
       << typeid(vpbd2).name() << endl
       << typeid(*vpbd2).name() << endl;  // Different, VDerived class

  return 0;
}
