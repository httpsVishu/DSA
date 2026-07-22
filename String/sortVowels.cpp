class Solution {
public:
    string sortVowels(string s) {
        //extract the vowels
        //since a and A are diff, make 2 diff arrays
        vector<int> upper(26, 0);
        vector<int> lower(26, 0);
        //vowel are 5, still taking 26: to map easily
        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                lower[s[i] - 'a']++;
                s[i] = '#';  //vowel ko # se replcae krdia taki jb sorted vowel ko vapsi dale to easy rhe find krne me
            }
            else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                upper[s[i] - 'A']++;
                s[i] = '#';
            }
            //uper else if hi likhna pdega, varna consonants ko bhi maanlega
        }

        //now sort the vowels and store in a variable, phle upper then lower as per ascii
        string ans;
        for (int i = 0; i < 26; i++){ //upper case
            char c = 'A' + i; //convert inot text
            while (upper[i]){ //jb tk value h keep adding
                ans += c;
                upper[i]--;
            }
        }
        for (int i = 0; i < 26; i++){ //lower case
            char c = 'a' + i; //convert inot text
            while (lower[i]){ //jb tk value h keep adding
                ans += c;
                lower[i]--;
            }
        }

        //place vowels at correct position
        int j = 0; //for iterating in ans
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '#'){ //# mtlb jaha vowel tha
                s[i] = ans[j];
                j++;
            }
        }
        return s;
    }
};