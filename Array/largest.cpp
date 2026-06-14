#include <iostream>
using namespace std;

int largestElement(int arr[], int size){
    int largest = arr[0];
    for (int i = 1; i < size; i++){
        if (arr[i] > largest){
            largest = arr[i];
        }
    }
    return largest;
}

int main(){
    int arr[] = {1,2,3,4,5};
    cout<<"Largest Element: "<< largestElement(arr, 5);
    return 0;
}