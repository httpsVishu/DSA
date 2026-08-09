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
class Solution {
public:
    int check(TreeNode* root){
        if (!root) return 0;
        int lh = check(root->left);
        //agar height -1 return ho to sidha lh ko -1 return krado
        if (lh == -1) return -1;

        int rh = check(root->right);
        if (rh == -1) return -1;

        //check for balanced
        if (abs(lh - rh) > 1) return -1;
        //balanced h to jo actual heigth h vo return kro as uper wale node ko uski jrurt h

        return 1 + max(lh, rh);
    }
    
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};

//balanced if balancing factor: lh - rh <= 1