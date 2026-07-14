class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int i = 0; // ye btaega kaha place krna h
        for (int j = 0; j < nums.size(); j++){
            if (nums[j] != val){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};


// yaha i count bta rha h kitne elements place huye, remove dupli wale ques me hm j = 1 se shuru kr rhe the mean vha first ko hmesha unique mana tha hence end me i me +1 kia tha, yha aisa nahi h