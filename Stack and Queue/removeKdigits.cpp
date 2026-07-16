class Solution {
public:
    //edge cases
    //1. agar k == n, means all char popped
    //2. what if "00100" remove leading zeroes
    //3. if nothing to pop "123456" k = 3, then pop last k digits

    string removeKdigits(string nums, int k) {
        int n = nums.size();
        if (n == k) return "0";

        stack<char> st;
        //traverse kro
        for (int i = 0; i < n; i++){
            //agar pichla el bda h to pop
            //make sure:
            //1. st empty na ho
            //2. k should be positive
            //3. agar top bda hua tbbi pop kro
            while (!st.empty() && k && st.top() > nums[i]){
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }

        //edge cases
        while (k){ //3.
            st.pop();
            k--;
        }
        //agar stack empty ho jaye to
        if (st.empty()) return "0";

        //ab apni string extract kro
        string res = "";
        while (!st.empty()){
            //res = res + st.top();
            //st.pop();
            
            //causes memory limit exceed

            res.push_back(st.top());
            st.pop();
        }
        //abhi hmari string reverse me h, to trailing 0 htao
        // ye compare krne me '0' krna pdega
        while (!res.empty() && res.back() == '0'){
            res.pop_back();
        }

        reverse(res.begin(), res.end());
        //agar stack me sirf '00000' hota to res empty ho jaega
        if (res.empty()) return "0";
        return res;
    }
};

// need to return "0" as return type is string, not char ('0')