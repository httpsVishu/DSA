class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorr = 0;
        for (int i = 0; i < nums.size(); i++){
            xorr = xorr^nums[i];
        }
        long rightmost = (xorr & (xorr-1)) ^ xorr;
        int ans1 = 0;
        int ans2 = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] & rightmost){
                ans1 = ans1 ^ nums[i];
            }
            else{
                ans2 = ans2 ^ nums[i];
            }
        }
        return {ans1, ans2};
    }
};

//phle sbhi el ka xor nikala, distinct walo ka bhi xor ho gya

// agar ye distinct the, so they miust be diff at min 1 bit

//we will find that bit using rightmost
// (n& n-1) isse rightmost set bit off hoti thi
// ^n krne se hme sirf rightmost bit on milegi

// ab is bit ke basis pe we will segegate el of array
// it will make sure both disitnct are segregated as they both differ at that

// agar ek same el ek variable me gya to dusra sathi bhi usi me jaega hence at the end xor krne pe we will get out final ans

//rightmost bit can be like this ----0000010000-- ab iska & hm el ke sath krenge jinke me 1 wali posiiton pe 1 hua vo ek varible, jinke me 0 hua vo 1&0=0 dega hence dusre variable me chle janege

// if xorr = -2^31
//then xorr-1 will be -2^31 -1 henec overflow therefore used long