/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    void preorder(Node* root, int level, vector<int>& res){
        if (!root) return;
        if (res.size() == level) res.push_back(root->data);
        preorder(root->left, level+1, res);
        preorder(root->right, level+1, res);
    }
    
    vector<int> leftView(Node *root) {
        vector<int> res;
        preorder(root, 0, res);
        return res;
    }
};