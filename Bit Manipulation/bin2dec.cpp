class Solution {
  public:
    int binaryToDecimal(string& b) {
        int n = b.size();
        int powOf2 = 1; //powOf2, will be updated every step, as of now 2^0 = 1
        int num = 0; //will store the decimal number so far
        
        for (int i = n-1; i >= 0; i--){
            if (b[i] == '1'){
                num = num + powOf2;
            }
            powOf2 *= 2; //make it next power: 1->2->4->8.......
        }
        
        return num;
    }
};