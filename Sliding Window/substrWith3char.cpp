class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastScene(3, -1);
        int cnt = 0;
        for (int i = 0; i < s.size(); i++){
            lastScene[s[i] - 'a'] = i;
            if (lastScene[0] != -1 && lastScene[1] != -1 && lastScene[2] != -1){
                cnt += (1 + min(lastScene[0], min(lastScene[1], lastScene[2])));
            }
        }
        return cnt;
    }
};

//last scene array leneg isme hm occurence dekhneg kis index pe aaya
//agar teeno me se koi non -1 h mtlb atleast encounter ho chuke h sb, hence no of substring we can form is min valus jo hogi (mltb yaha se hme char milna shur ho gya tha) , usme +1 krna h

//also min takes 2 arg only hence use nested