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
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track, TreeNode* target){
        //simple bfs krke har node ke parent ko store krlo map me
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            //ek ek node lete jao, agar child h to queue me bhi dalte rho and map me parent store krate rho
            if (curr->left){
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right){
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //ek map bnao to keep track of nodes ke parents ka, then pass in function
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParents(root, parent_track, target);
        //ek map lelo visited wale yaad rkhne ke liye
        unordered_map<TreeNode*, bool> visited;

        //ek or bar bfs lagao but now from target, k distance tk jaenge , using hashing info
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        while (!q.empty()){
            int size = q.size();
            if (curr_level == k) break;
            for (int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                //left child h and vo unvisited h
                if (curr->left && !visited[curr->left]){
                    q.push(curr->left); //q me dalo
                    visited[curr->left] = true; //visited me mark krdo
                }
                //right child h and vo unvisited h
                if (curr->right && !visited[curr->right]){
                    q.push(curr->right); //q me dalo
                    visited[curr->right] = true; //visited me mark krdo
                }
                //ab parent ko bhi dekho, coz k distance me hm parent side bhi ja skte h
                if (parent_track[curr] && !visited[parent_track[curr]]){
                    q.push(parent_track[curr]); //curr ke parent ko q me daldo
                    visited[parent_track[curr]] = true; //curr ke parent ko visited me true krdo
                }
            }
            curr_level++;
        }
        vector<int> res;
        while (!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            res.push_back(curr->val);
        }
        return res;
    }
};