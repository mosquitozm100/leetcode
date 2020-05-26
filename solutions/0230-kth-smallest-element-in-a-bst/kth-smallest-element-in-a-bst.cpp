// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
//  
//
// Example 1:
//
//
// Input: root = [3,1,4,null,2], k = 1
//    3
//   / \
//  1   4
//   \
//    2
// Output: 1
//
// Example 2:
//
//
// Input: root = [5,3,6,2,4,null,null,1], k = 3
//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
// Output: 3
//
//
// Follow up:
// What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
//
//  
// Constraints:
//
//
// 	The number of elements of the BST is between 1 to 10^4.
// 	You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
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
    unordered_map<TreeNode *, int> NumOfChilds;
    int dfs(TreeNode * root){
        if(root == NULL) return 0;
        int num = 1;
        num += dfs(root -> left);
        num += dfs(root -> right);
        NumOfChilds[root] = num;
        return num;
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        while(1){
            int numLeft = ((root -> left) == NULL) ? 0 : NumOfChilds[root -> left];
            if(numLeft == k - 1) return root -> val;
            else if(numLeft < k - 1) {
                root = root -> right;
                k -= (numLeft + 1);
            }
            else if(numLeft > k - 1){
                root = root -> left;
            }
        }
        return 0;
    }
};
