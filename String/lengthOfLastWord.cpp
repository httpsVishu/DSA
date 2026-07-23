class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        //phle make sure to get at non space char
        int j;
        for (int i = n-1; i >= 0; i--){
            if (s[i] != ' '){   //make sure we reach at first non space char
                j = i;
                break;
            }
            else{
                n--;   //e.g "hi moon    " jb hm n- i -1 krenge to us n me last ke space bhi h hence unhe minus krna h size se
            }
        }
        //now we at non space char, traverse till space
        for (int i = j; i >= 0; i--){
            if (s[i] == ' ') return (n - i - 1);   //jaise hi hme space encounter hoga beech ka return this
        }
        return n;    //agar ek hi word ki string simply return n;
    }
};