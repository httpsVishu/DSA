class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        //for lopp n-m tk chlegi as n-m ke baad needle me check krne ke liye characters ni honge
        for (int i = 0; i <= n-m; i++){
            int first = i;
            int second = 0;
            while (second < m){  //ab match krte rho
                if (haystack[first] != needle[second]){
                    //mtlb not matched hence break
                    break;
                }
                else{
                    //agle wale check krte rho
                    first++;
                    second++;
                }
            }
            //agar second m ke equal hua mtlb all matched
            if (second == m) return first - second;
        }
        return -1;
    }
};

//at end:
// abcdef    first pointing to d (index 3)
// abc       second pointing to m as got outside (index 3)

// 3-3 = 0; hence got the index where string matches