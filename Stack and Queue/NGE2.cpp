class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for (int i = 2*n - 1; i >=0; i--){
            while (!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            if (i < n){
                ans[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
};

// n to 2n walo ke liye hme NGE allot ni krna hence
// sirf push krenge


//2nd part ko sirf push kro, first half ke liye value finalise kro