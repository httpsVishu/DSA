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
class BSTiterator{
    stack<TreeNode*> myStack;
    bool reverse = true;
    // reverse = true    -> before
    // reverse = false     -> next

public: 
    BSTiterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
        //jis hisab ka reverse hoga, us hisab se pushAll call hoga
    }

    bool hasNext() {
        return !myStack.empty();
    }

    int next(){
        TreeNode* temp = myStack.top();
        myStack.pop();
        //agar reverse true hua mtlb before, left pe jao and pushAll left elements call krega
        if (reverse == true) pushAll(temp->left);
        else pushAll(temp->right);

        return temp->val;
    }

private:
    void pushAll(TreeNode* node){
        for (; node != nullptr;){
            //phle node ko push in stack
            myStack.push(node);
            //reverse true h mtlb before
            if (reverse == true) node = node->right;
            else node = node->left;

        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        BSTiterator l(root, false);  //mtlb LNR
        BSTiterator r(root, true);   //mtlb RNL

        int i = l.next();
        int j = r.next();   //this next is basically before

        while (i < j){
            if (i + j == k) return true;
            else if (i + j < k){
                if (!l.hasNext()) return false;
                i = l.next();
            }
            else{
                if (!r.hasNext()) return false;
                j = r.next();
            }
        }

        return false;
    }
};

//2 sum use kia h, pointers bas start and end node pe leke gye hai