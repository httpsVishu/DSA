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
    void reverseLL(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp != nullptr){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
    }

    ListNode* findKthNode(ListNode* temp, int k){
        k -= 1;
        while (temp != nullptr && k > 0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next) return head;

        ListNode* temp = head;
        ListNode* prevNode = nullptr;
        while (temp){
            ListNode* kthNode = findKthNode(temp, k);
            if (kthNode == nullptr){
                if (prevNode){
                    prevNode->next = temp;
                }
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;

            reverseLL(temp);

            if (temp == head){
                head = kthNode;
            }
            else{
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp->next = nextNode;
            temp = temp->next;
        }
        return head;
    }
};