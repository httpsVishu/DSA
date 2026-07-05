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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) return nullptr;

        ListNode* temp = head;
        int cnt = 0;
        while (temp != nullptr){
            cnt++;
            temp = temp->next;
        }
        if (n > cnt) return head;

        //nth node from end is (cnt-n+1)th node from start
        int k = (cnt - n + 1);

        if (k == 1) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        int cnt2 = 0;
        while (curr != nullptr){
            cnt2++;
            if (cnt2 == k){
                prev->next = curr->next;
                delete curr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};