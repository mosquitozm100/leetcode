//
// Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
//
//
//
// Example:
// Given a binary tree 
//
//           1
//          / \
//         2   3
//        / \     
//       4   5    
//
//
//
// Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
//
//
// Note:
// The length of path between two nodes is represented by the number of edges between them.
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int len = 0;
        return mydiameterOfBinaryTree(root, len);
    }
    int mydiameterOfBinaryTree(TreeNode* root, int &longestSubstring) {
        if(root == NULL) return 0;
        int lenLeft =  -1, lenRight = -1;
        int ans = max(mydiameterOfBinaryTree(root -> left, lenLeft), mydiameterOfBinaryTree(root -> right, lenRight));
        longestSubstring = max(lenLeft, lenRight) + 1;
        if(root -> left == NULL) ans = max(ans, lenRight + 1);
        else if(root -> right == NULL) ans = max(ans, lenLeft + 1);
        else ans = max(ans, lenLeft + 1  + lenRight + 1);    
        return ans;
    }
};
