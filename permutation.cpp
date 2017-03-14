#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

void perm(int list[], int k, int m) {
  if (k == m) {
    copy(list, list + m + 1, ostream_iterator<int>(cout, " "));
    cout << endl;
    return;
  }
  
  for (int i = k; i <= m; ++i) {
    swap(list[k], list[i]);
    perm(list, k + 1, m);
    swap(list[k], list[i]);
  }
}

int main(int argc, char* argv[]) {
  int lst[10] = {1, 2, 3, 4, 5};
  perm(lst, 0, 4);

  return 0;
}
