class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0; //first distinct value pe i rhega 
        for (int j = 1; j < nums.size(); j++){
            if (nums[j] != nums[i]){ // find first non equivalent element
                i++;       //jab non equivalent mil jaega to i se agli posiiton pe use place krdenge
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};