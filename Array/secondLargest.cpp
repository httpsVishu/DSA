#include <iostream>
using namespace std;

int secLargestElement(int arr[], int n){
    int largest = arr[0];
    int secLargest = -1;

    for (int i = 0; i < n; i++){
        if (arr[i] > largest){
            secLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secLargest && arr[i] != largest){
            secLargest = arr[i];
        }
    }
    return secLargest;
}

int main(){
    int arr[] = {1,2,3,4,5};
    cout<<"Largest Element: "<< secLargestElement(arr, 5);
    return 0;
}