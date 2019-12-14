// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
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
// return its level order traversal as:
//
// [
//   [3],
//   [9,20],
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        if(root != NULL) q.push(root);
        vector<vector<int> > ans;
        while(!q.empty()){
            int m = q.size();
            vector<int> tmp;
            while(m--){
                TreeNode * e = q.front();q.pop();
                tmp.push_back(e -> val);
                if(e -> left != NULL) q.push(e -> left);
                if(e -> right != NULL) q.push(e -> right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
