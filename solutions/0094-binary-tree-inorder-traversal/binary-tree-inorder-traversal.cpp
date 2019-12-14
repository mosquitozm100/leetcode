// Given a binary tree, return the inorder traversal of its nodes' values.
//
// Example:
//
//
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
//
// Output: [1,3,2]
//
// Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return vector<int>();
        vector<int> ans;
        vector<int> left = inorderTraversal(root -> left);
        ans.insert(ans.end(), left.begin(), left.end());
        ans.push_back(root -> val);
        vector<int> right = inorderTraversal(root -> right);
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }
};
