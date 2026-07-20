class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> mpp;
        int n = s.size();
        int m = t.size();
        for (int i = 0; i < n; i++){
            mpp[s[i]]++;
        }
        for (int i = 0; i < m; i++){
            mpp[t[i]]--;
        }
        for (auto it: mpp){
            if (it.second != 0){
                return it.first;
            }
        }
        return '\0';
    }
};

// aabbb
//aabbba

// jitni frequency s badhaega utni t kam krdega hence end me normal char ki freq 0 hogi, jiski 0 nhi hui mtln usko cancel krne wala koi ni tha


//or just use fuckin XOR as all char appear twice except one

class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        for (auto c: s) ans = ans^c;
        for (auto c: t) ans = ans^c;
        return ans;
    }
};


// as dono string har char ka pair bnega except that extra char, hence or vo dedega