/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertNodeInBetween(Node* head){
        Node* temp = head;
        while (temp){
            Node* nextNode = temp->next;
            Node* newNode = new Node(temp->val);
            newNode->next = nextNode;
            temp->next = newNode;
            temp = nextNode;
        }
    }

    void attachRandomPointers(Node* head){
        Node* temp = head;
        while (temp){
            Node* copyNode = temp->next;
            if (temp->random){
                copyNode->random = temp->random->next;
            }
            else copyNode->random = nullptr;

            temp = temp->next->next;;
        }
    }

    Node* getDeepCopy(Node* head){
        Node* dummy = new Node(-1);
        Node* res = dummy;
        Node* temp = head;
        while (temp){
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        insertNodeInBetween(head);
        attachRandomPointers(head);
        return getDeepCopy(head);
    }
};