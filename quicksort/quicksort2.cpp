#include <iostream>
#include <cstdlib>

using namespace std;

void quick_sort(int arr[], int low, int high) {
  int pivot = arr[low];
  int left = low, right = high;
  do { 
    while (left <= right && arr[left] < pivot) {
      left++;
    }
    while (left <= right && arr[right] > pivot) {
      right--;
    }
    if (left <= right) {
      swap(arr[left], arr[right]);
      left++;
      right--;
    }
  } while (left <= right);
  if ( low < right) {
    quick_sort(arr, low, right);
  }
  if (left < high) {
    quick_sort(arr, left, high);
  }
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
