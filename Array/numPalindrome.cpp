
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int temp = x;
        int pal;
        int curr = 0;
        while (temp){
            pal = temp % 10;
            curr = curr*10 + pal;
            temp = temp / 10;
        }
        return curr == x;
    }
};