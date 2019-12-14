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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        if(root != NULL) q.push(root);
        vector<vector<int> > ans;
        int dir = 1;
        while(!q.empty()){
            int m = q.size();
            vector<int> tmp;
            while(m--){
                TreeNode * e = q.front();q.pop();
                tmp.push_back(e -> val);
                if(e -> left != NULL) q.push(e -> left);
                if(e -> right != NULL) q.push(e -> right);
            }
            if(dir == -1) reverse(tmp.begin(), tmp.end());
            dir = -dir;
            ans.push_back(tmp);
        }
        return ans;
    }
};
