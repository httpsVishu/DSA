/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>> ans;
        Node* tail = head;
        while (tail->next != nullptr){
            tail = tail->next;
        }
        Node* temp = head;
        
        while ((temp->data) < (tail->data)){
            long sum = temp->data + tail->data;
            if (sum == target){
                ans.push_back({temp->data, tail->data});
                temp = temp->next;
                tail = tail->prev;
            }
            else if (sum < target) temp = temp->next;
            else tail = tail->prev;
        }
        return ans;
    }
};