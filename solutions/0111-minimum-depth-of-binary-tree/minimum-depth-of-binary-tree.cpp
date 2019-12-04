// Given a binary tree, find its minimum depth.
//
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given binary tree [3,9,20,null,null,15,7],
//
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
// return its minimum depth = 2.
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
    int dfs(TreeNode * root){
        if(root -> left == NULL && root -> right == NULL) return 1;
        int ans = 10000;
        if(root -> left != NULL) ans = min(ans,minDepth(root -> left));
        if(root -> right != NULL) ans = min(ans,minDepth(root -> right));
        return ans + 1;
    }
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return dfs(root);
    }
};
