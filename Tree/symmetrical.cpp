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
    bool isSymmhelp(TreeNode* left, TreeMode* right){
        //agar ek bhi null ho gya to
        if (left == null || right == null){
            return (left == right);
            //dekho dono same h kya
        }
        if (left->val != right->val){
            //agar dono ki val alg hui
            return false;
        }
        return isSymmHelp(left->left, right->right) &&
        isSymmHelp(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return (root == null) || isSymmHelp(root->left, root->right);
    }
};


//phle left ke left and right ke right ko call kor
//then mirror me left ka right dekhna hoga and then right ka left