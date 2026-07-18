class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n-1)) == 0;
    }
};

// can also write (n>0)&&(n & (n-1)) == 0

// 1,2,4,8,16,..... all have only 1 set bit in binary form
//1
//10
//100
//1000

//hence is bit ko turn off krdo using n & n-1 
//8 : 1000
//7 : 0111
//n-1 hmesha 2 ki power ko chodke agle bits banata h
//inka add krne pe 0 aa rha h hence power of 2;

//as power of 2 me 1 hi set bit hoti h , to and krne pe hmesha 0 aana chaiye else not