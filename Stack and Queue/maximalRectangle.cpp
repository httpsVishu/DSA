class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int maxArea = 0;
        int nse, pse, element;
        for (int i = 0; i < arr.size(); i++){
            //pse nikal lo
            while (!st.empty() && arr[st.top()] > arr[i]){
                //piche ki trf ja rhe h hence nse bhi nikl skta h
                element = st.top();
                st.pop();
                ///agar top bda tha mtlb abhi ith wala chota, hence element ke hisab se ith is nge;
                nse = i;
                pse = st.empty() ? -1 : st.top();
                int area = arr[element]*(nse - pse - 1);
                maxArea = max(maxArea, area);
            }
            st.push(i); //index push krna h
        }
        //ab agar koi elemnt stack me bacha ho to uske liye nse and pse dekhna h
        while (!st.empty()){
            nse = arr.size(); //ye hmesha n hi hoga= arr size
            element = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();
            int area = arr[element]*(nse - pse - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxArea = 0;
        vector<vector<int>> preSum(n, vector<int>(m,0));
        //create prefix sum matrix
        for (int j = 0; j < m; j++){
            int sum = 0;
            for (int i = 0; i < n; i++){
                //sum += mat[i][j];
                //agar vo 0 ho to pura sum 0 krdo
                //if (mat[i][j] == 0) sum = 0;
                //preSum ke usi jagah sum ko place krdo

                //cant use above logic, as matrix val are given as char instead of int, hence do as:
                if (mat[i][j] == '1') sum++;
                else sum = 0;
                preSum[i][j] = sum;
            }
        }

        for (int i = 0; i < n; i++){
            maxArea = max(maxArea, largestRectangleArea(preSum[i]));
        }

        return maxArea;
    }
};