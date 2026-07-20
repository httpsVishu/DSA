class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = -1;
        //j ko zero el pe le jao
        for (int i = 0; i < n; i++){
            if (nums[i] == 0){
                j = i;
                break;
            }
        }

        if (j == -1) return ; //means no zeroes

        for (int i = j+1; i < n; i++){
            if (nums[i] != 0){
                swap(nums[i], nums[j]);  //swap krdo zero and non zero el ko
                j++;
            }
        }

        return ;
    }
};