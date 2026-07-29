class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (int i = 0; i < s.size(); i++){
            if (isalnum(s[i])){
                str += tolower(s[i]);
            }
        }
        int l = 0; 
        int r = str.size() - 1;
        while (l < r){
            if (str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};