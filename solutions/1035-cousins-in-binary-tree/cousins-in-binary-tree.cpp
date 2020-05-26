// In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
//
// Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
//
// We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
//
// Return true if and only if the nodes corresponding to the values x and y are cousins.
//
//  
//
// Example 1:
//
//
//
// Input: root = [1,2,3,4], x = 4, y = 3
// Output: false
//
//
//
// Example 2:
//
//
//
// Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
// Output: true
//
//
//
// Example 3:
//
//
//
//
// Input: root = [1,2,3,null,4], x = 2, y = 3
// Output: false
//
//
//
//
//  
// Constraints:
//
//
// 	The number of nodes in the tree will be between 2 and 100.
// 	Each node has a unique integer value from 1 to 100.
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
    bool find(TreeNode * root, int curdepth, int value, int & depth, int & father){
        if(root == NULL) return false;
        if(root -> val == value) {
            depth = curdepth;
            return true;
        }
        else {
            if(find(root -> left, curdepth+1, value, depth, father)) father = root -> val;
            if(find(root -> right, curdepth+1, value, depth, father)) father = root -> val;
        }
        return false;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int depth1 = 0, depth2 = 0;
        int f1 = 0, f2 = 0;
        find(root, 0, x, depth1, f1);
        find(root, 0, y, depth2, f2);
        if(depth1 == depth2 && f1 != f2) return true;
        else return false;
    }
};
