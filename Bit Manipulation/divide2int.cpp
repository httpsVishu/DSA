class Solution {
public:
    int divide(int dividend, int divisor) {
        //handle normal cases
        if (dividend == divisor) return 1;
        if (divisor == 1) return dividend;
        //hm +ve number ke loye solve krenge, end me sign lga denge

        bool sign = true;
        //either of them is -ve = -ve
        if (dividend > 0 && divisor < 0) sign = false;
        if (dividend < 0 && divisor > 0) sign = false;

        //make them +ve to computer ache se
        //long n = abs(dividend);
        //long d = abs(divisor);
        long long ans = 0;
        //using long as if n = -2^31, doing abs make it +2^31 hence overflow hence use long

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        //using LL as per lc suggestions

        while (n >= d){ //jb tk n bda h d se
            int cnt = 0; //ye basically 2 ki power btaega
            while (n >= (d << (cnt+1))){//hm max kitni d * 2 ki power ko n se hata skte h
                cnt++;
            }
            ans = ans + (1LL << cnt); //2 ki powers ko ans me store kro, basically ye quotient h, inhe d se kitna mutiply krne p remove kr skte h
            n = n - (d << cnt); // n me se itna hata do
        }
        //overflow cases
        if (ans > INT_MAX) {
            return sign ? INT_MAX : INT_MIN;
        }
        return sign ? ans : (-1 * ans);
    }
};

// d * 2^31 ko d * (1<<31) likh skte h using left shift

//left shift : means mutiply with 2 ki power something
//right shift: divide by 2 ki power seomthing


//ans = ans + (1LL << cnt);    wriitng as 1 << cnt may  overflow when cnt = 31;