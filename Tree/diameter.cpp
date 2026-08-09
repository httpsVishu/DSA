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
    int diameter(TreeNode* root, int& d){
        if (!root) return 0;
        int lh = diameter(root->left, d);
        int rh = diameter(root->right, d);
        d = max(d, lh + rh);
        return 1 + max(lh, rh);
        //height return krte rhna, d ko maintain krte rhna
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        diameter(root, d);
        return d;
    }
};

//path niklega kisi node ke leftheight and rioghtheight ka sum krke, max lete rhna to find the max diameter