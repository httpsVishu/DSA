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
private:
    TreeNode* first, *middle, *prev, *last;

    void inorder(TreeNode* root){
        if (!root) return ;

        inorder(root->left);
        //do your business
        if (prev != nullptr && root->val < prev->val){
            //prev bada ho gya mtlb vioaltion
            //agar first null hua means first violation h
            if (!first){
                first = prev;
                middle = root;
            }
            else{
                //mtlb 2nd violation
                last = root;
            }
        }
        //ye niche wali line har node ke liye
        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);   //ques me bola h ye aisa karne
        inorder(root);
        //agar first and last dono non null huye means non adjacenet, hence unhe swap kro
        if (first && last) swap(first->val, last->val);
        else if (first && middle) swap(first->val, middle->val);
        //mtlb adjacent hence swap consecutive wale
    }
};

//logic is: inorder krte chlo
//take a note kaha kaha violaation ho rha h, agar 2 violation mile to swap
//agar 1 mila means adjacent h swap