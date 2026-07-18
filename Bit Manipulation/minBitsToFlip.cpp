class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while (n != 0){
            n = n & (n-1);
            cnt++;
        }
        return cnt;
    }

    int minBitFlips(int start, int goal) {
        int ans = start^goal;
        return hammingWeight(ans);
    }
};

//hamming weight means number of set bits
// start and goal ka xor krne pe jo bits alg alg homgi dono me vo 1 bana degi, ab un 1 ko count krna pdega

//10: 1010
//7:  0111
//xor: 1101  <---- ab in 1 ko count kro