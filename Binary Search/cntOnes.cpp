// if row elements sorted

class Solution {
public:
    int lb(vector<int> arr, int n, int x){
        int low = 0;
        int high = n-1;
        int ans = n;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (arr[mid] >= x){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }

    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int cnt_max = 0;
        int index = -1;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++){
            int val = lb(mat[i], m, 1);
            int cnt_ones = m - val;
            if (cnt_ones > cnt_max){
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return {index, cnt_max};
    }
};

//if row elements not sorted

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxCnt = -1;
        int ind = -1;
        for (int i = 0; i < mat.size(); i++){
            int cntRow = 0;
            for (int j = 0; j < mat[0].size(); j++){
                cntRow += mat[i][j];
            }
            if (cntRow > maxCnt){
                maxCnt = cntRow;
                ind = i;
            }
        }
        return {ind, maxCnt};
    }
};