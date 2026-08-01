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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);

        ListNode* curr1 = dummy1;
        ListNode* curr2 = dummy2;

        ListNode* temp = head;
        while (temp != nullptr){
            if (temp->val < x){
                curr1->next = temp;
                curr1 = curr1->next;
            }
            else{
                curr2->next = temp;
                curr2 = curr2->next;
            }
            temp = temp->next;
        }
        curr2->next = nullptr; //explicitly end 2nd
        curr1->next = dummy2->next;
        return dummy1->next;
    }
};