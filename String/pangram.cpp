class Solution {
public:
    bool checkIfPangram(string sent) {
        //letter agar aa rhe h to true krdo
        vector<bool> alpha(26, 0);
        for (int i = 0; i < sent.size(); i++){
            alpha[sent[i] - 'a'] = true;
        }
        //traverse, agar 1 bhi false rha to not pangram
        for (int i = 0; i < sent.size(); i++){
            if (alpha[i] == false) return false;
        }
        return true;
    }
};