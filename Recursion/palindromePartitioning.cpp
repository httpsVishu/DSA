class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while (start <= end){
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }

    void check(int index, string s, vector<string>& path, vector<vector<string>>& res){
        //base case
        if (index == s.size()){
            res.push_back(path);
            return ;
        }
        //loop lgao, har next char se dekho kya utne tk ki string palidnrome h, if yes aage chlo, if not stop
        for (int i = index; i < s.size(); i++){
            if (isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i - index + 1));
                check(i + 1, s, path, res);
                //jb fn call khtm, pop krdo
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        check(0, s , path, res);
        return res;
    }
};