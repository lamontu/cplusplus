#include <iostream>
#include <cstdlib>

using namespace std;

int partition(int* arr, int low, int high) {
  int left = low;
  int right = high;
  int temp = arr[low];
  while (left < right ) {
    while (left < right && arr[right] >= temp) {
      --right;
    }
    if (left < right) {
      arr[left] = arr[right];
    }

    while (left < right && arr[left] <= temp) {
      ++left;
    }
    if (left < right) {
      arr[right] = arr[left];
    }
  }
  arr[left] = temp;
  return left;
}

void quick_sort(int arr[], int low, int high) {
  int pivot;
  if (low < high) {
    pivot = partition(arr, low, high);
    quick_sort(arr, low, pivot - 1);
    quick_sort(arr, pivot + 1, high);
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
