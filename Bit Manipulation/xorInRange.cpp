class Solution {
 public:
    //this fn is based on obseravtion at every 4th step
    int findXORtillN(int n){
        if (n%4==1) return 1;
        else if (n%4==2) return n+1;
        else if (n%4==3) return 0;
        else return n;
    } 
    
    int findXOR(int l, int r) {
        return findXORtillN(l-1) ^ findXORtillN(r);
    }
};

// let l = 3
// let r = 6
// fn (l-1) = 1^2 ( 3 not included )
//fn (r) = 1^2^3^4^5^6
//inka apas me xor : (1^2) ^ (1^2^3^4^5^6)
//same wale cancel hence 3^4^5^6 ans



// TC: O(1)