/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 // TC: O(n) for putting in string + O(n) for dec2bin
 //SC: O(n)
class Solution {
public:
    int binaryToDecimal(string& b) {
        int n = b.size();
        int powOf2 = 1; //powOf2, will be updated every step, as of now 2^0 = 1
        int num = 0; //will store the decimal number so far
        
        for (int i = n-1; i >= 0; i--){
            if (b[i] == '1'){
                num = num + powOf2;
            }
            powOf2 *= 2; //make it next power: 1->2->4->8.......
        } 
        return num;
    }

    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        string bin = "";
        while (temp){
            bin += (temp->val + '0'); //as bin is string and val is int
            temp = temp->next;
        }
        int ans = binaryToDecimal(bin);
        return ans;
    }
};