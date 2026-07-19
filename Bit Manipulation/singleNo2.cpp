class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); //jisse same el cluster bana le
        // [2,2,2,3,4,4,4]
        // ab middle wale el ko har bar pichle se krna h
        //hence start from 1
        for (int i = 1; i < n; i = i+3){
            if (nums[i] != nums[i-1]){
                //mtlb hmara single el comes before the dupli ones
                return nums[i-1];
            }
        }
        //in case hm loop se bahar aa jaye and since single number is guaranteed, its the last one
        return nums[n-1];
    }
};

//TC: O(nlogn) + O(n/3) 
//not good as we are distorting the original array


// TC: O(n) SC: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        for (int i = 0; i < nums.size(); i++){
            ones = (ones^nums[i])&~twos;
            twos = (twos^nums[i])&~ones;
        }
        return ones;
    }
};

// 2 bucket bana li, ones and twos

//cond 1: el ones me jaega agar el twos me nhi hua to
//con 2: el twos me jaega agar vo ones me hua to
//cond 3: agar twos me hua to ones and twos at the end 0 ho jaenge , no need of third bucket

//[2,2,2,1]]
//is example se smjhna, as sarai chize bits level pe hoti h to smjhne me muskhil hoti h

//rest of the explanation is in the notebook