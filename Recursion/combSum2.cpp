class Solution {
public:
    void findComb(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds){
        //target 0 ho to ans me daaldo
        if (target == 0){
            ans.push_back(ds);
            return ;
        }
        //loop lgao ith index se aage jitne bhi el h, sbko dekhenge if it can be picked, agar pichle wlaa same ho, to dont pick
        for (int i = ind; i < arr.size(); i++){
            if (i > ind && arr[i] == arr[i-1]) continue;
            if (arr[i] > target) break;
            ds.push_back(arr[i]);
            findComb(i+1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        findComb(0, target, candidates, ans, ds);
        return ans;
    }
};

//why i > ind
//ye sirf first iteriton me false hoga
//e.g. 1,1,1,1,2,2,2
//           i
//dekho, i ab 1 pe h, isme bhi pichla dekha to vo qual h to use bhi include krenge, i > ind krne pe sirf vo and uske aage ke dekhenge
//hence need to use this condition