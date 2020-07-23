// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
//
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
//
//
// return its zigzag level order traversal as:
//
// [
//   [3],
//   [20,9],
//   [15,7]
// ]
//
//


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
        vector<vector<int> > ans;
        if(root == NULL) return ans;
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int len = q.size();
            vector<int> tmp;
            for(int i = 0; i< len;i++){
                TreeNode * t = q.front();q.pop();
                tmp.push_back(t -> val);
                if(t -> left != NULL)  q.push(t -> left);
                if(t -> right != NULL) q.push(t -> right);
            }
            if(level & 1) reverse(tmp.begin(), tmp.end());
            level++;
            ans.push_back(tmp);
        }
        return ans;
    }
};
