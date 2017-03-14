#include <iostream>

using namespace std;

void func(const int& v1, const int& v2) {
  cout << v1 << ' ';
  cout << v2 << ' ';
}

int main(int argc, char* argv[]) {
  int i = 0;
  func(++i, i++);
  return 0;
}
