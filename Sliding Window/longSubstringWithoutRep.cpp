class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //ek hash array banao of size 256
        vector<int> hash(256, -1);
        //-1 means no index
        int n = s.size();
        int l = 0;
        int r = 0;
        int maxLen = 0;
        while (r < n){
            //agar -1 nhi h to mtlb char already substring me h
            if (hash[s[r]] != -1){
                //usme bhi agar l ke baad ana chaiye coz l se hi string shuru ho rhi h
                if (hash[s[r]] >= l){
                    l = hash[s[r]] + 1; //l ko ek aage krdo
                }
            }
            //mltb -1 h, hence find len
            int len = r - l + 1;
            maxLen = max(len, maxLen);
            //array update kro
            hash[s[r]] = r; //update with index
            r++;
        }
        return maxLen;
    }
};