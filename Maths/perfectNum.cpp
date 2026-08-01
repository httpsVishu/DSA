class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;
        //1 is not perfect as need prorper divisor

        int sum = 1; //1 se hmesh divide hota h to 1 ko phle hi add krdo and start loop from 2
        for (int i = 2; i <= num/2; i++){
            if (num % i == 0){
                sum += i;
            }
        }
        return num == sum;
    }
};