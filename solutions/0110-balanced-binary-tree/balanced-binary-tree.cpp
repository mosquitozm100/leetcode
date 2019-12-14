// Given a binary tree, determine if it is height-balanced.
//
// For this problem, a height-balanced binary tree is defined as:
//
//
// a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
//
//
//  
//
// Example 1:
//
// Given the following tree [3,9,20,null,null,15,7]:
//
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
// Return true.
//
// Example 2:
//
// Given the following tree [1,2,2,3,3,null,null,4,4]:
//
//
//        1
//       / \
//      2   2
//     / \
//    3   3
//   / \
//  4   4
//
//
// Return false.
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
    int getDepth(TreeNode * root){
        if(root == NULL) return 0;
        int leftDepth = getDepth(root -> left);if(leftDepth == -1) return -1;
        int rightDepth = getDepth(root -> right);if(rightDepth == -1) return -1;
        if(abs(leftDepth - rightDepth) > 1) return -1;
        return max(leftDepth, rightDepth) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(getDepth(root) == -1) return false;
        else return true;
    }
};
