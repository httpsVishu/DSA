class Solution {
public:
    //phle prefix max nikal lo, ki piche konsa el max h and then suffixMax nikal lena for next max el
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> preMax(n, 0);
        vector<int> suffMax(n, 0);
        preMax[0] = arr[0];
        for (int i = 1; i < n; i++){
            preMax[i] = max(arr[i], preMax[i-1]);
        }
        suffMax[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--){
            suffMax[i] = max(arr[i], suffMax[i+1]);
        }

        int total = 0;
        for (int i = 0; i < n; i++){
            int leftMax = preMax[i];
            int rightMax = suffMax[i];
            if (arr[i] < leftMax && arr[i] < rightMax){
                total += (min(leftMax, rightMax) - arr[i]);
            }
        }

        return total;
    }
};