class Solution {
public:
    int subarrayWithLEK(vector<int>& arr, int k){
        if (k == 0) return 0;

        int l = 0;
        int r = 0;
        int cnt = 0;
        map<int, int> mpp;
        while (r < arr.size()){
            mpp[arr[r]]++;
            while (mpp.size() > k){
                mpp[arr[l]]--;
                if (mpp[arr[l]] == 0) mpp.erase(arr[l]);
                l++;
            }
            //ab pkka valid hoga
            cnt = cnt + (r - l + 1);
            r++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrayWithLEK(nums, k) - subarrayWithLEK(nums, k-1);
    }
};