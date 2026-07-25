class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int maxlen = -1;
        int l = 0;
        int r = 0;
        map<char, int> mpp;
        while (r < s.size()){
            mpp[s[r]]++;
            if (mpp.size() > k){
                mpp[s[l]]--;
                if (mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }
            if (mpp.size() == k){
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};


//same as fruits into basket problemm

//isme goven h ki sirf lowercase h hence 26 h, if all char, then use 256

//ye gfg ki promblem, isme exactly pucha h hence
//maxlen intiially -1 lia h
//and mpps.size() == k (since exactly)