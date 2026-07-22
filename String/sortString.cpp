class Solution {
  public:
    string sortString(string &s) {
        //make array for ocurences, jiski jitni occurences, utni bar print krdo
        vector<int> alpha(26, 0);
        for (int i = 0; i < s.size(); i++){
            alpha[s[i] - 'a']++;
        }
        //ab print krado jb tk sb 0 na ho jaye
        string ans;
        for (int i = 0; i < 26; i++){
            char c = 'a' + i;   //int se char me convert kro as we need characters
            while (alpha[i]){ //jb tk count 0 na ho jaye
                ans += c;
                alpha[i]--;
            }
        }
        return ans;
    }
};

//TC: 0(n) + 0(26)