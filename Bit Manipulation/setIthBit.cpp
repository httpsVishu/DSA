class Solution {
  public:
    int setKthBit(int n, int k) {
        return n | (1 << k);
    }
};


// 1 ko k times left le aao ir or krdo, baki eleemnts aise hi aa jaenge,
// agr 0 hua kth to 1 se and krke 1 ho jaega hence set
//1 hua to 1 hi rhega