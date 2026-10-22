/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root){
            if (root->val > p->val && root->val > q->val){
                root = root->left;
            } else if (root->val < p->val && root->val < q->val){
                root = root->right;
            } else {
                return root;
            }
        }
        return nullptr;
    }
};

//4 case hai: both lie on left, both lie on right, one on left one on right, nide itself one of two

//first two tell where to go, last two tell ans
//in case path split or node itself is one of 2 num, it is the LCA