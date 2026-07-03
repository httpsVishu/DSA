class Solution {
public:
    int countSmallEqual(vector<vector<int>> mat, int n, int m, int x){
        int cnt = 0;
        for (int i = 0; i < n; i++){
            cnt += (upper_bound(mat[i].begin(), mat[i].end(), x) - mat[i].begin());
        }
        return cnt;
    }
    
    int median(vector<vector<int>> &mat) {
        int low = INT_MAX;
        int high = INT_MIN;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++){
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m-1]);
        }
        int req = (m*n)/2;
        while (low <= high){
            int mid = low + (high - low)/2;
            int smallEqual = countSmallEqual(mat, n, m, mid);
            if (smallEqual <= req) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};
