class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) return false;
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }
        return st.size() != nums.size();
    }
};