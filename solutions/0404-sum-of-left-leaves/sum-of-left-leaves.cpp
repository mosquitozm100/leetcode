// Find the sum of all left leaves in a given binary tree.
//
// Example:
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
// There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
    int calc(TreeNode * root){
        int ret = 0;
        if(root == NULL) return 0;
        if(root -> left != NULL)    ret += calc(root->left);
        if(root -> right != NULL)   ret += calc(root->right);
        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL) ret += root->left->val;
        return ret;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = calc(root);
        return ans;
    }
};
