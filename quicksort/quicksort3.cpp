#include <iostream>
#include <cstdlib>

using namespace std;

void quick_sort(int arr[], int low, int high) {
  if (low > high) return;
  int value = arr[low];
  int left = low, right = high;
  while (left < right) {
    for (; left < right; --right) {
      if (arr[right] < value) {
        arr[left++] = arr[right];
        break;
      }
    }
    for (; left < right; ++left) {
      if (arr[left] > value) {
        arr[right--] = arr[left];
        break;
      }
    }
  }
  arr[left] = value;
  quick_sort(arr, low, left - 1);
  quick_sort(arr, left + 1, high);
}

int main() {
  int arr[10];
  for (int i = 0; i < 10; ++i) {
    arr[i] = random() % 100;
  }
  for (int i = 0; i < 10; ++i) {
    cout << arr[i] << ", ";
  }
  cout << endl;

  quick_sort(arr, 0, 9);

  for (int i = 0; i < 10; ++i) {
    cout << arr[i] << ", ";
  }
  cout << endl;
  return 0;
}
