class Solution {
  public:
    void sumS(int ind, int sum, vector<int>& arr, int n, vector<int>& subset){
        //jb index size tk phoch jaye to stop and push in ans
        if (ind == n){
            subset.push_back(sum);
            return;
        }
        //left tree call kro, pick case
        sumS(ind + 1, sum + arr[ind], arr, n, subset); //pick kia to next ind pe jao and sum me add kro
        sumS(ind + 1, sum, arr, n, subset); //pick ni kia to sirf ind aage kia
    }
    
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> subset;
        sumS(0, 0, arr, arr.size(), subset);
        //if asked to sort, sort(subset.begin(), subset.end());
        return subset;
    }
};