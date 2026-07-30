class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256, 0); //to keep occurence of char in t

        int l = 0;
        int r = 0;
        int minlen = INT_MAX;
        int cnt = 0;
        int sIndex = -1;
        
        //preinsert characetrs of t in hash
        for (int i = 0; i < t.size(); i++){
            hash[t[i]]++;
        }

        //ab s ke char ko dkehte chlo
        while (r < s.size()){
            //agar hash me vo preinseretd h, means +ve h
            if (hash[s[r]] > 0) cnt++; //means has same char as t
            hash[s[r]]--; //always decrement krte chlo

            //bas jb value +ve ho t cnt++ kro

            while (cnt == t.size()){ //mtlb we have got a valid substring, need to find minimum
                if (r - l + 1 < minlen){
                    minlen = r - l + 1;
                    sIndex = l;
                }
                hash[s[l]]++; //hash me is jagah -ve value h na, to use increment krne ke liye +ve side lek jaenge
                if (hash[s[l]] > 0) cnt--;
                //mltb t ka vo char substring se ht gya, isiliye hash me +ve dikh rha h
                l++;
            }
            r++;
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minlen);
    }
};