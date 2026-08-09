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
    int maxPath(TreeNode* node, int& maxi){
        if (!node) return 0;
        int leftSum = max(0, maxPath(node->left, maxi));
        //incase maxPAth negtive return kre, take max with 0
        int rightSum = max(0, maxPath(node->right, maxi));
        //incase maxPAth negtive return kre, take max with 0
        maxi = max(maxi, node->val + leftSum + rightSum);
        return node->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root, maxi);
        return maxi;
    }
};

//jis node pe rehke fn call krenge left and irgth wala, that node will act as curve point

//maxi variable rkhenge to keep  track kis path ka sum max aaega 

//maxi ki value leftsum and rigthsum ko us node ki val ke sath add krne pe aaegi

//return me hme node ki val + leftsum and rightsum me max wala  bhejna pdega

//e.g. node = 5, l = 4, r = 3
//to return 5+4 krna pdega as agli node ke liye max sum 9 hoga