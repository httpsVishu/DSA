class Solution {
  public:
    bool checkKthBit(int n, int k) {
        return (n & (1<<k)) != 0;   //0 ni aaye, baki chahe kuch aa jaye
    }
};

// n & (1 << k)    1 ko kth place tk le aao, then and krdo, agar set hui to ` aa jaega as 1&1 =

//using right shift

// (n >> k) & 1     n ko k tk right le aao fir 1 se and krdo, 1 aa gya to set h