#include <iostream>

using namespace std;

class ClassA {
 public:
  virtual void FunctionA() {}
};

class ClassB {
 public:
  virtual void FunctionB() {}
};

class ClassCab: public ClassA, public ClassB {
 public:
};

class ClassCba: public ClassB, public ClassA {
 public:
};

int main() {
  ClassCab cab;
  ClassA* pAa = &cab;
  ClassB* pBa = &cab;
  ClassCab* pCab = &cab;
  cout << "pAa = " << pAa << endl;
  cout << "pBa = " << pBa << endl;
  cout << "pCab = " << pCab << endl;
  cout << endl;
  
  ClassCba cba;
  ClassA* pAb = &cba;
  ClassB* pBb = &cba;
  ClassCba* pCba = &cba;
  cout << "pAb = " << pAb << endl;
  cout << "pBb = " << pBb << endl;
  cout << "pCba = " << pCba << endl;
  return 0;
}
