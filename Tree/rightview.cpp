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
    void preorder(TreeNode* root, int level, vector<int>& res){
        if (!root) return ;
        //agr level ki value size ke equal ho, means we are seeing that level for first time
        if (res.size() == level) res.push_back(root->val);
        //need to reverse traverse pre order hence right phle
        preorder(root->right, level+1, res);
        preorder(root->left, level+1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        preorder(root, 0, ans);
        return ans;
    }
};