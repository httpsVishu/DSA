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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* temp = head;
        ListNode* temp2 = head->next;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while (temp && temp2){
            ListNode* temp3 = temp2->next;
            curr->next = temp2;
            temp2->next = temp;
            curr = temp;

            temp = temp3;
            temp2 = temp3 ? temp->next : nullptr;
        }
        if (temp) curr->next = temp;
        else curr->next = temp2;
        return dummy->next;
    }
};