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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while (!q.empty()){
            int size = q.size(); //find current size of q at each new iteration, hr level ke liye alg size
            vector<int> row(size); //jitne q me abhi el honge, utne hi row vector me dalenge
            //loop lgao and push in vector
            for (int i = 0; i < size; i++){
                //extract node from queue
                TreeNode* node = q.front();
                //pop krdo
                q.pop();
                //ab uska index dekho based on flag
                int index = (flag) ? i : (size - 1 - i);
                //insert
                row[index] = node->val;
                //insert their child if exist
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            //hr level ke baaf flip the flag
            flag = !flag;
            //ans me row ko daaldo
            ans.push_back(row);
        }
        return ans;
    }
};


//simple logic: ek flag mainatin rkkre rkho false hua to r->l true hua to l->r