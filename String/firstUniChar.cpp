class Solution {
public:
    int firstUniqChar(string s) {
        for (int i = 0; i < s.size(); i++){
            bool flag = false;;
            for (int j = 0; j < s.size(); j++){
                if (i != j && s[i] == s[j]){
                    flag = true;
                    break;
                }
            }
            if (!flag) return i;
        }
        return -1;
    }
};

//brute force as O(n^2)

//optimal: TC O(2n) SC (26)

class Solution {
public:
    int firstUniqChar(string s) {
        int frequency[26] = {0};
        //hr char ki freq store krlo
        for (int i = 0; i < s.size(); i++){
            frequency[s[i] - 'a']++;
        }
        //fir s pe loop lga ke char access kro, jiski sabse phle 1 aaye return krdo
        for (int i = 0; i < s.size(); i++){
            if (frequency[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};

