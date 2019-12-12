// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
//
//
//  
//
// But the following [1,2,2,null,3,null,3] is not:
//
//
//     1
//    / \
//   2   2
//    \   \
//    3    3
//
//
//  
//
// Note:
// Bonus points if you could solve it both recursively and iteratively.
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
    bool isFlap(TreeNode * s, TreeNode * t){
        if(s == NULL && t == NULL) return true;
        else if(s == NULL || t == NULL) return false;
        return (s -> val == t -> val) && isFlap(s -> left, t -> right) && isFlap(s -> right, t -> left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        else return isFlap(root -> left, root -> right);
    }
};
