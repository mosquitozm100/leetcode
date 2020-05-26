// Return the root node of a binary search tree that matches the given preorder traversal.
//
// (Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)
//
// It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.
//
// Example 1:
//
//
// Input: [8,5,1,7,10,12]
// Output: [8,5,10,1,7,null,12]
//
//
//
//  
// Constraints:
//
//
// 	1 <= preorder.length <= 100
// 	1 <= preorder[i] <= 10^8
// 	The values of preorder are distinct.
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode * root = new TreeNode(preorder[0]);
        TreeNode * tmp = root;
        unordered_map<TreeNode*, TreeNode *> fatherOfLeft;
        for(int i = 1;i < preorder.size();i++){
            TreeNode * tmp = root;
            while(true){
                if(preorder[i] < tmp -> val){
                    if(tmp -> left == NULL) {
                        TreeNode * newnode = new TreeNode(preorder[i]);
                        tmp -> left = newnode;
                        break;
                    }else tmp = tmp -> left;
                }
                else{
                    if(tmp -> right == NULL) {
                        TreeNode* newnode = new TreeNode(preorder[i]);
                        tmp -> right = newnode;
                        break;
                    }else tmp = tmp -> right;
                }
            }
        }
        return root;
    }
};
