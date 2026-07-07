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

 // brute force 
 
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

//using fast and slow pointer

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
        if (head == nullptr) return nullptr;

        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < n; i++){
            fast = fast->next;
        }
        if (fast == nullptr){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        while (fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
};