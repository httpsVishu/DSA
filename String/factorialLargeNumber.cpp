class Solution {
  public:
    vector<int> factorial(int m) {
        //sbse phle 1 block ka vector leleo with value 1
        vector<int> ans(1, 1);
        //fact is n*n-28...*3*2*1: multiplication with 1 is usefkess hence we will do till 2 only
        while (m > 1){
            int carry = 0; //jo carry aaega use store krne k liye
            int res; //store partial product of indidviual digits
            int n = ans.size(); // next loop ans ke size tk chlegi, whey? co jitne digits utni bar n se mutpliy
            for (int i = 0; i < n; i++){
                res = ans[i] * m + carry;   //ans ke ith element se n ki mutpliy kro and carry ho to add kro
                carry = res/10;
                //ab ans ke ith element ki value update kro
                ans[i] = res%10;
                //for loop will make sure hr digit ke sath ho jaye
            }
            //agar carry bach jaye, sidha 1 block me mt daalo, each digit diff block
            while (carry){
                ans.push_back(carry%10);
                carry = carry/10;
            }
            //jab ek n ki value ke liye ho jaye make it n-1 then n-2 ... upto 2
            m--;
        }
        //ans is in opp order, hence reverse
        reverse(ans.begin(), ans.end());
        return ans;
    }
};