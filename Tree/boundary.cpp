/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isLeaf(Node* root){
        return (!root->left && !root->right);
    }
    
    void addLeftBound(Node* root, vector<int>& res){
        Node* curr = root->left;
        //coz root ko hm already push rk chuke
        while (curr){
            //agar node leaf nhi h tbbi push kro
            if (!isLeaf(curr)) res.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    void addLeaf(Node* root, vector<int>& res){
        if (isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        if (root->left) addLeaf(root->left, res);
        if (root->right) addLeaf(root->right, res);
    }
    
    void addRightBound(Node* root, vector<int>& res){
        Node* curr = root->right;
        vector<int> temp;
        while (curr){
            if (!isLeaf(curr)) temp.push_back(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        //ab temp ke el ko reverse me put kro in res
        for (int i = temp.size() -1 ; i >= 0; i--){
            res.push_back(temp[i]);
        }
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if (!root) return res;
        //in case ek hi node hua to vo to leaf mana jaega, therefore add a check
        if (!isLeaf(root)) res.push_back(root->data);
        addLeftBound(root, res);
        addLeaf(root, res);
        addRightBound(root, res);
        return res;
    }
};




//phle left boundary ko lo exlcuding leaf
//thn lef nodes using inorder
//then right bouindary excluding lead in reverse


//boundary leni h hence left side me curr ko left side bhjenege agar exist krta h to and on right side
// curr ke rigth me hi bhejenge