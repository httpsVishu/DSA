class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++){
            while (!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            
            ans[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};

// prev nikalna h to aage se hi shuru krenge dhundhna
// smaller nikalna h to top bada ni hona chaiye, agar hua to pop krdo
