class Solution {
public:
    void genPermute(vector<int>& ds, vector<vector<int>>& ans, vector<int>& nums, vector<int>& freq){
        //if all el pciked mtlb ds ka size nums ke equal
        if (ds.size() == nums.size()){
            ans.push_back(ds);
            return ;
        }
        for (int i = 0; i < nums.size(); i++){
            if (!freq[i]){ //agr pick ni hua
                ds.push_back(nums[i]);
                freq[i] = 1;
                genPermute(ds, ans, nums, freq);
                //fn call khtm to freq ko 0 krdo and pop
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(), 0);
        genPermute(ds, ans, nums, freq);
        return ans;
    }
};


//no  extra space

class Solution {
public:
    void genPermute(int index, vector<int>& nums, vector<vector<int>>& ans){
        if (index == nums.size()){ //base case, put in ans
            ans.push_back(nums);
            return ;
        }
        //loop laga do har index pe
        for (int i = index; i <nums.size(); i++){
            swap(nums[index], nums[i]);
            genPermute(index + 1, nums, ans);
            swap(nums[index], nums[i]); //fn call khmt hote hi phle jaisa bana do
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        genPermute(0, nums, ans);
        return ans;
    }
};