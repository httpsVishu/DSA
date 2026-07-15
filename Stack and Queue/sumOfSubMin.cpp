class Solution {
public:
    vector<int> PSEE(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++){
            while (!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    // hme = htana pdega to avoid duplicate subarrays
    vector<int> NSE(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for (int i = n-1; i >= 0; i--){
            while (!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    // hm element nhi index push krenge to find contributors

    // NGE me empty hone pe N ho ga PSEE me -1 hi rhega

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nge = NSE(arr);
        vector<int> psee = PSEE(arr);
        int total = 0;
        int mod = (int)(1e9 + 7);
        for (int i = 0; i < arr.size(); i++){
            int left = i - psee[i];
            int right = nge[i] - i;
            total = (total + (right*left*1LL*arr[i])%mod)%mod;
        }
        return total;
    }
};

//left me hme left wale suitable mil jaenge
//right me hme right wale mil jaenge
// right* left se hme suitable conitbrutons mil jaenge, unhe typecast kro, 
//fir multiply by element itself to find total effect

