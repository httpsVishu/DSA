class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        if (arr.empty() || arr.size() == 1) return arr;
        
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++){
            if (arr[i] > 0){  //agar positive el h
                ans.push_back(arr[i]);
            }
            else{ // // agar negative hua to
                while (!ans.empty() && ans.back() > 0 && ans.back() < abs(arr[i])){
                    ans.pop_back();
                }

                if (!ans.empty() && ans.back() == abs(arr[i])){
                    ans.pop_back();
                }
                
                else if (ans.empty() || ans.back() < 0){
                    ans.push_back(arr[i]);
                }
            }
        }
        return ans;
    }
};

// pop tb hoga agar
//1. agar list empty nhi h
//2. last elemnt positive h
//3. last element chota na ho negative ke abs se

// agar equal collision h to pop kro or aage chlo
// else if is important 
//e.g. [5, -5]

//5 to push ho gya
// jb -5 aya vo 2nd if me gya, to vo 5 ko nikal dega and go ahead
//therefore both destroyed and ans = []

//but agar else if nhi lgate to third contion bhi true ho jaega as ans is empty 
//therefore -5 get pushed to ans

//hence wrong 