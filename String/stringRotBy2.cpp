class Solution {
public:
    void rotateClock(string& s1){
        int n = s1.size();
        char c = s1[n-1];
        for (int i = n-1; i > 0; i--){ //cant write 1 to n-1 varna agle letter overwrite ho jaeng
            s1[i] = s1[i-1];    // i 0 se phle tk khtm krna h varna 0-1 = -1 invalid aa jaega
        }
        s1[0] = c;
    } 
    
    void rotateAntiClock(string& s2){
        int n = s2.size();
        char c = s2[0];
        for (int i = 1; i < n; i++){
            s2[i-1] = s2[i];
        }
        s2[n-1] = c;
    } 
    
    bool isRotated(string& s1, string& s2) {
        if (s1.size() != s2.size()) return false;
        
        string clock = s1, anti = s1;
        rotateClock(clock);
        rotateClock(clock);
        if (clock == s2) return true;
        
        rotateAntiClock(anti);
        rotateAntiClock(anti);
        if (anti == s2) return true;
        
        return false;
    }
};
