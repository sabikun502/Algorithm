#include<iostream>
using namespace std;
void InsertionSort(int arr[],int n)
{
 for(int i=1;i<n;i++)
 {
     int curr = arr[i];
     int prev = i-1;
     while(prev >= 0 && arr[prev] > curr)
     {
         arr[prev+1] = arr[prev];
         prev--;
     }
     arr[prev+1] = curr;
 }

}
void printArray(int arr[],int n) {
    for (int i = 0;i<n;i++) {
        cout<< arr[i] << " ";
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
    InsertionSort(arr, n);
    cout <<"Sorted Array: ";
    printArray(arr, n);
    return 0;
}
