// Given the root of a binary tree, return the inorder traversal of its nodes' values.
//
// Follow up: Recursive solution is trivial, could you do it iteratively?
//
//  
// Example 1:
//
//
// Input: root = [1,null,2,3]
// Output: [1,3,2]
//
//
// Example 2:
//
//
// Input: root = []
// Output: []
//
//
// Example 3:
//
//
// Input: root = [1]
// Output: [1]
//
//
// Example 4:
//
//
// Input: root = [1,2]
// Output: [2,1]
//
//
// Example 5:
//
//
// Input: root = [1,null,2]
// Output: [1,2]
//
//
//  
// Constraints:
//
//
// 	The number of nodes in the tree is in the range [0, 100].
// 	-100 <= Node.val <= 100
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
