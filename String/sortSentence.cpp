class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);
        string temp;
        int count = 0;
        int index = 0;
        while (index < s.size()){
            if (s[index] == ' '){ //agar space aa jaye
                int n = temp.size();
                int pos = temp[n - 1] - '0'; //pos ko store krlo
                temp.pop_back(); //pos hata do
                ans[pos] = temp; //ab word ko ans me store krlo usi index pe = pos
                temp.clear();
                count++;
            }
            else{

                temp += s[index];
            }
            index++;
        }
        //agar loop ke bhar aa gaye to last word still in temp
        int n = temp.size();
        int pos = temp[n - 1] - '0'; //pos ko store krlo
        temp.pop_back(); //pos hata do
        ans[pos] = temp; //ab word ko ans me store krlo usi index pe = pos
        temp.clear();
        count++;

        for (int i = 1; i <= count; i++){
            temp += ans[i];
            temp += ' ';
        }
        temp.pop_back(); //last extra space ko hta do
        return temp;
    }
};