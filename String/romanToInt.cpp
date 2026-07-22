class Solution {
public:
    int num(char c){
        if (c == 'I') return 1;
        else if (c == 'V') return 5;
        else if (c == 'X') return 10;
        else if (c == 'L') return 50;
        else if (c == 'C') return 100;
        else if (c == 'D') return 500;
        else return 1000;
    }
    int romanToInt(string s) {
        //agar agla char bada hota h to current -ve ho jata h, hence run loop before n-1
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n-1; i++){
            if (num(s[i]) < num(s[i+1])){
                sum -= num(s[i]);
            }
            else{
                sum += num(s[i]);
            }
        }
        //since last char rehta h abhi
        sum += num(s[n-1]);
        return sum;
    }
};