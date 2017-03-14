#include <iostream>

using namespace std;

int main() {
  float a[3][4];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
      a[i][j] =  i * 10 + j;
    }
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
      // Wrong ansewer: cout << *(a+4*i+j) << '\t';
      cout << *(*a+4*i+j) << '\t';
      // Below are also OK;
      // cout << *(a[i]+j) << '\t';
      // cout << *(*(a+i)+j) << '\t';
    }
    cout << endl;
  }
}
