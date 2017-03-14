#include <iostream>

using namespace std;

const int i3 = 0;

int main() {
  // int const i1 = 0;  // same as below, const qualified variable i1
  const int i1 = 0;
  int* j1 = (int*)&i1;
  cout << "i1 = " << i1 << ", "
       << "*j1 = " << *j1 << endl;
  // i1 = 6;  // Error
  *j1 = 3;  // OK
  cout << "i1 = " << i1 << ", "
       << "*j1 = " << *j1 << endl;

  cout << "------------------------------" << endl;
  volatile const int i2 = 0;
  int* j2 = (int*)&i2;
  cout << "i2 = " << i2 << ", "
       << "*j2 = " << *j2 << endl;
  // i2 = 6;  // Error
  *j2 = 3;  // OK
  cout << "i2 = " << i2 << ", "
       << "*j2 = " << *j2 << endl;

  cout << "------------------------------" << endl;
  int* j3 = (int*)&i3;
  cout << "i3 = " << i3 << ", "
       << "*j3 = " << *j3 << endl;
  //i3 = 6;  // Error
  *j3 = 3;  // Bus error: 10
  cout << "i3 = " << i3 << ", "
       << "*j3 = " << *j3 << endl;

  return 0;
}
