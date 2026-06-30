class Solution {
public:
    bool noOfBalls(vector<int>& arr, int mid, int m){
        int cntBall = 1;
        int force = arr[0];
        int n = arr.size();
        for (int i = 1; i < n; i++){
            if (arr[i] - force >= mid){
                cntBall++;
                force = arr[i];
            }
            if (cntBall >= m) return true;
        }
        return false;
    }

    int maxDistance(vector<int>& arr, int m) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int low = 1;
        int high = arr[n-1] - arr[0];
        while (low <= high){
            int mid = (low + high)/2;
            int balls = noOfBalls(arr, mid, m);
            if (balls == true) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};