class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxlen = 0;
        int l = 0;
        int r = 0;
        map<int, int> mpp;
        while (r < fruits.size()){
            //phle fruit ko daldo in map
            mpp[fruits[r]]++;
            //agar size 2 se jyada ho gya to reduce. agar koi 0 ho gya to erase
            if (mpp.size() > 2){
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }
            //agar <=2 h to count fruits = length since consecutive
            if (mpp.size() <= 2){
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};