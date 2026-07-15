class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for (int i = n-1; i >= 0; i--){
            while (!st.empty() && st.top() >= arr[i]){
                st.pop();
            } 
            
            ans[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};

//ditto same NGE ki trah h
//1. next dhundhna h to aage walo ka pta hona chaiye hence piche se shuru krenge
//2. smaller hai to top ko bda nhi hona chaiye, agar bda hua to pop krdenge


// NGE me greater dhundhna hota h to top ko chota nhi hona chaiye