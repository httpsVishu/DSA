/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> myStack;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        //top node ko store krao amd pop kro
        TreeNode* temp = myStack.top();
        myStack.pop();
        // us node ke right element ke jitne bhi left ho insert krao, as we need to go extreme left for inorder
        pushAll(temp->right);
        //fir apne temp ko return krado
        return temp->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }

private:
    void pushAll(TreeNode* root){
        for (; root != nullptr; myStack.push(root), root = root->left);
    }
};

//constructor ka kaam hoga, call hote hi jitni bhi left noes h unhe stack me daalde

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */