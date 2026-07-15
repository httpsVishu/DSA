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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while (temp){
            if (temp->val != val){
                curr->next = temp;
                curr = curr->next;
            }
            temp = temp->next;
        }
        curr->next = nullptr; //make sure curr ke baad koi unwanted eleemnt na ho
        return dummy->next;
    }
};

// LC 203