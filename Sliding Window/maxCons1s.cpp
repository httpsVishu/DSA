class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int zeros = 0;
        int l = 0; 
        int r = 0;
        while (r < n){
            //agr el 0 hua to increase zero
            if (nums[r] == 0) zeros++;
            //agar z > k hua to 2 case h: el == 0 to zero-- krdo and l++, agr el !=0 then sirf l++ kro
            if (zeros > k){
                if (nums[l] == 0){ zeros--;}
                l++;
            }
            //agar z <= k hua to find len
            //z > k rha to l++ hota rhega us case me niche wala check nhi chlega sidha r++ ho jaega
            if (zeros <= k){
                int len = r - l + 1;
                maxLen = max(len, maxLen);
            }
            r++;
        }
        return maxLen;
    }
};

//agar maxLen phoch jao e.g. 5 and then zeros>k ho jayee to 1 1 krke window shirnk krna h as maxLen pe frk pdega ni hence no use of doing everything at once vrna TC increases