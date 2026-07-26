class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxlen = 0;
        int maxf = 0;
        vector<int> hash(26, 0);
        while (r < s.size()){
            //el ki freq update in hash
            hash[s[r] - 'A']++;
            //al ki freq dali h to maxf bhi dekho
            maxf = max(maxf, hash[s[r] - 'A']);
            //check if inavlid to -- krdo
            if ((r-l+1) - maxf > k){
                hash[s[l] - 'A']--;
                l++;
            }
            //make sure invalid rha to sidha r++ pe jump krega
            if ((r-l+1) - maxf <= k){
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};