#include <iostream>
using namespace std;
void quickSort(int arr[], int low, int high) {
    if (low >= high) return;
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    int pi = i + 1;
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
     int n ;
    cout << "Enter number of elements: ";
    cin>>n;
    int arr[n];
  cout << "Enter Numbers: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    cout << "Sorted Array: ";
    printArray(arr, n);
    return 0;
}

