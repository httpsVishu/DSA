/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; */

class Solution {
  public:
    Node* merge(Node* h1, Node* h2){
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        
        while (h1 && h2){
            if (h1->data < h2->data){
                temp->bottom = h1;
                temp = h1;
                h1 = h1->bottom;
            }
            else{
                temp->bottom = h2;
                temp = h2;
                h2 = h2->bottom;
            }
            temp->next = nullptr; 
        }
        if (h1) temp->bottom = h1;
        else temp->bottom = h2;
        
        if (dummy->bottom) dummy->bottom->next = nullptr;
        return dummy->bottom;
    }
    
    Node *flatten(Node *head) {
        if (!head || !head->next) return head;
        
        Node* mergeHead = flatten(head->next);
        head = merge(head, mergeHead);
        return head;
    }
};