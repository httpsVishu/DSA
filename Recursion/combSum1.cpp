class Solution {
public:
    void findComb(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds){
        //base, agar ind size ke barabar hua and target 0 hua
        if (ind == arr.size()){
            if (target == 0){
                ans.push_back(ds);
            }
            return ;
        }
        //jb tk ith el target se chota h ya equal h, we can pick ith el again and again
        if (arr[ind] <= target){
            ds.push_back(arr[ind]);
            findComb(ind, target - arr[ind], arr, ans, ds);
            //jo el dala h use nikalna bhi;
            ds.pop_back();
        }
        findComb(ind + 1, target, arr, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findComb(0, target, candidates, ans, ds);
        return ans;
    }
};