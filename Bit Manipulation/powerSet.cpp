class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subsets = 1 << n; //2^n means 1 << n
        vector<vector<int>> ans;
        for (int num = 0; num < subsets; num++){ // for n = 3, 0 to 7 tk chlega
            vector<int> list;
            for (int i = 0; i < n; i++){ //arr ke elements me traverse kro
                if (num & (1 << i)){
                    list.push_back(nums[i]);
                }
            }
            ans.push_back(list);
        }
        return ans;
    }
};