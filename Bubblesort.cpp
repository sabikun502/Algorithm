#include<iostream>
using namespace std;
void bubbleSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
   {
        bool isSwap = false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]> arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap)
            return;
    }
}
void printArry(int arr[],int n)
{
   for(int i=0;i<n;i++)
   {
       cout<<arr[i]<<" ";
   }
   cout<<endl;
}
int main() {
     int n = 5;
    int arr[n];
    cout << "Enter Number: "<< n ;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    bubbleSort(arr,n);
    cout << "Bubble Sort: ";
    printArry(arr,n);
    return 0;
}

