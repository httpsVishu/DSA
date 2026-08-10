/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if (!root) return ans;
        map<int, int> mpp; //for keeping a check ki us line pe phle se koi el h?
        queue<pair<Node*, int>> q; //to push levels
        q.push({root, 0});   //root ko daaldo with level 0
        while (!q.empty()){
            //ek ek el ko nikalo
            auto it = q.front();
            //pop krte jao
            q.pop();
            //extrcat individual values
            Node* node = it.first;
            int line = it.second;
            //agar mpp me nhi h to add kro
            if (mpp.find(line) == mpp.end()) mpp[line] = node->data;
            //ab chidl insert krdo
            if (node->left) q.push({node->left, line - 1});
            if (node->right) q.push({node->right, line + 1});
        }
        //ab map se traverse krke lelo, map give in sorted order
        for (auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};


//pproahc, assume straigth lines, jo jo line pe phle aye vo ans me lelo