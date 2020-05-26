// Given a non-empty binary tree, find the maximum path sum.
//
// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
//
// Example 1:
//
//
// Input: [1,2,3]
//
//        1
//       / \
//      2   3
//
// Output: 6
//
//
// Example 2:
//
//
// Input: [-10,9,20,null,null,15,7]
//
//    -10
//    / \
//   9  20
//     /  \
//    15   7
//
// Output: 42
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
    int ans = 0;
    int maxPathSumTra(TreeNode * root){
        if(root == NULL) return 0;
        int left = maxPathSumTra(root -> left), right = maxPathSumTra(root -> right);
        if(left < 0) left = 0;
        if(right < 0) right = 0;
        ans = max(ans, left + right + (root -> val));
        return max(left + (root -> val), right + (root -> val));
    }
    int maxPathSum(TreeNode* root) {
        ans = (root -> val);
        maxPathSumTra(root);
        return ans;
    }
};
