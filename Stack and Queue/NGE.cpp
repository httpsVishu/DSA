class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for (int i = n-1; i >= 0; i--){
            while (!st.empty() && st.top() <= arr[i]){
                st.pop();
            } 
            
            ans[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};


//leetcode 496: arr me NGE nikalo and nums ki value ke liye find kro

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums, vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        unordered_map<int, int> mpp;
        for (int i = n-1; i >= 0; i--){
            while (!st.empty() && st.top() <= arr[i]){
                st.pop();
            } 
            mpp[arr[i]] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }
        //now find values for nums
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++){
            ans.push_back(mpp[nums[i]]);
        }
        return ans;
    }
};


//we use hasmap to find values later 