#include <iostream>

using namespace std;


void f() {
  static int a;
  static int b = 10;
  int c = 10;
  a++;
  b++;
  c++;
  cout << "a = " << a << ", "
       << "b = " << b << ", "
       << "c = " << c << endl;
}


int main() {
  for (int k = 0; k < 5; ++k) {
    f();
  }

  return 0;
}
