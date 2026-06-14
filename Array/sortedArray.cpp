#include <iostream>
#include <vector>
using namespace std;

int isSorted(int n, vector<int> arr){
    for (int i = 1; i < n; i++){
        if (arr[i] >= arr[i-1]){

        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> arr = {1,2,4,3,5};
    cout<<"Is Array Sorted? (0: No, 1: Yes) "<< isSorted(5, arr);
    return 0;
}