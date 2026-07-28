class Solution {
public:
    int SumAtmostGoal(vector<int>& nums, int goal){
        //wrote this base case coz <= k me to kbhi ni hoega lekin next func me goal -1 kr rhe h hence need it 
        if (goal < 0) return 0;

        int l = 0;
        int r = 0;
        int cnt = 0;
        int sum = 0;
        while (r < nums.size()){
            //el ko sum me add krdo
            sum += nums[r]%2;
            //if sum > k, keep reducing till valid, hence trim from left
            while (sum > goal){
                sum -= nums[l]%2;
                l++;
            }
            //ab valid h to count kitne bn skte h, r - l + 1 se bnenge, explanantion notebook me
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return SumAtmostGoal(nums, k) - SumAtmostGoal(nums, k-1);
    }
};