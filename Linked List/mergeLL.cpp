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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        vector<int> arr;
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        while (t1 || t2){
            if (t1){
                arr.push_back(t1->val);
                t1 = t1->next;
            }
            if (t2){
                arr.push_back(t2->val);
                t2 = t2->next;
            }
        }

        sort(arr.begin(), arr.end());

        ListNode* head = new ListNode(arr[0]);
        ListNode* curr = head;
        long long i = 1;
        while (i < arr.size()){
            ListNode* newNode = new ListNode(arr[i]);
            curr->next = newNode;
            curr = curr->next;
            i++;
        }
        return head;
    }
};