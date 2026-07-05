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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        stack<int> st;
        ListNode* temp = head;
        while (temp != nullptr){
            st.push(temp->val);
            temp = temp->next;
        }
        ListNode* temp2 = head;
        while (temp2 != nullptr){
            temp2->val = st.top();
            st.pop();
            temp2 = temp2->next;
        }
        return head;
    }
};