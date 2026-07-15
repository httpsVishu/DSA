class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++){
            long long largest = nums[i];
            long long smallest = nums[i];
            for (int j = i+1; j < nums.size(); j++){
                largest = max(largest, 1LL*nums[j]);
                smallest = min(smallest, 1LL*nums[j]);
                sum += (largest - smallest);
            }
        }
        return sum;
    }
};


//burte force h, optimised wala is easy but i was too lazy to code that