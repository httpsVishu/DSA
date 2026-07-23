class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> alpha(26, 0);
        for (int i = 0; i < s.size(); i++){
            alpha[s[i] - 'a']++;
            alpha[t[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; i++){
            if (alpha[i] != 0) return false;
        }
        return true;
    }
};

//s string ki occurence ko array me ++ krao
// t srting ki occurence ko -- krao

//ye dono chize ek hi loop me kr skte ho
//coz dono ka size same hi h, hence at the end dono string ke sbhi char store ho jaenge
// at the end, sb 0 hona chaiye varna kisi ka na kisi ki occurneec jyada h dusri string se

//also size same hona chiaye, varna definitely nahi h