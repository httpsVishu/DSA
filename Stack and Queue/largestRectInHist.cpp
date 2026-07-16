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
};

//nse - pse - 1 hme width dega, use arr[element] yani ki height se multiply krke area milega