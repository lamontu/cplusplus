#include <iostream>

using namespace std;

const int N = 2;

void prim(int m, int n=N) {
  if (m >= n) {
    while (m % n) {
      n++;
    }
    m /= n;
    prim(m, n);
    cout << n << endl;
  }
}


int main() {
  prim(60, 2);  // prim(60, 1)  // segmentation fault 11
  return 0 ;
}
