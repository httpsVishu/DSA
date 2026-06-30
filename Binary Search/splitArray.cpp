class Solution {
public:
    int func(vector<int>& arr, int mid){
        int n = arr.size();
        int el = 1;
        long long sum = arr[0];
        for (int i = 1; i < n; i++){
            if (sum + arr[i] <= mid){
                sum += arr[i];
            }
            else{
                el++;
                sum = arr[i];
            }
        }
        return el;
    }

    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        if (k > n) return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        while (low <= high){
            int mid = low + (high - low)/2;
            int val = func(arr, mid);
            if (val > k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};