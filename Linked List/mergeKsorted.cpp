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


 //better sol   O(n x k x k + 1)/2

class Solution {
public:
    ListNode* merge(ListNode* h1, ListNode* h2){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        
        while (h1 && h2){
            if (h1->val < h2->val){
                temp->next = h1;
                temp = h1;
                h1 = h1->next;
            }
            else{
                temp->next = h2;
                temp = h2;
                h2 = h2->next;
            }
        }
        if (h1) temp->next = h1;
        else temp->next = h2;
        
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        ListNode* head = lists[0];
        for (int i = 1; i < lists.size(); i++){
            head = merge(head, lists[i]);
        }
        return head;
    }
};

// optimal using priority queue;

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
    
        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>
        > pq;
        //k x log(k)
        for (int i = 0; i < lists.size(); i++){
            if (lists[i]){
                pq.push({lists[i]->val, lists[i]});
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        
        while (!pq.empty()){ //n x k
            auto it = pq.top();  //logk
            pq.pop();  //logk
            if (it.second->next){
                pq.push({it.second->next->val, it.second->next}); //logk
            }
            temp->next = it.second;
            temp = temp->next;
        }
        return dummy->next;
    }
};

// (k x logk) + (n x k x (log k + log k + log k))
//(k x logk) + (n x k x (3 x log k))
//(k x logk) + (n x k x log k)
