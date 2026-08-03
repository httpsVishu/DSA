class Solution {
  public:
    void findSubset(int ind, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans){
        //jo bhi ds me h push in ans, help us to push from empty subset itself
        ans.push_back(ds);
        for (int i = ind; i < arr.size(); i++){
            if (i != ind && arr[i-1] == arr[i]) continue; //mtlb its the duplicate el in current iteration
            ds.push_back(arr[i]);
            findSubset(i+1, arr, ds, ans);
            //jb call khtm ho jaye pop last filled el
            ds.pop_back();
        }
    }
    
    vector<vector<int>> findSubsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubset(0, nums, ds, ans);
        return ans;
    }
};