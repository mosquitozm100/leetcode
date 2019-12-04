// Given the root of a binary tree, each node in the tree has a distinct value.
//
// After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
//
// Return the roots of the trees in the remaining forest.  You may return the result in any order.
//
//  
// Example 1:
//
//
//
//
// Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
// Output: [[1,2,null,4],[6],[7]]
//
//
//  
// Constraints:
//
//
// 	The number of nodes in the given tree is at most 1000.
// 	Each node has a distinct value between 1 and 1000.
// 	to_delete.length <= 1000
// 	to_delete contains distinct values between 1 and 1000.
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
    bool deleteOneNumber(vector<TreeNode *>& forest, vector<TreeNode*> &add_list, TreeNode * root, int &  number){  //return whether this node still exists.
        if(root == NULL) return false;
        //printf("%d\n", root -> val);
        bool deleteLeftResult = deleteOneNumber(forest, add_list, root -> left, number);
        bool deleteRightResult = deleteOneNumber(forest, add_list, root -> right, number);
        if(number == root -> val) {
            if(deleteLeftResult)  add_list.push_back(root -> left);
            if(deleteRightResult) add_list.push_back(root -> right);
            return false;
        }
        if(deleteLeftResult == false) root -> left = NULL;
        if(deleteRightResult == false) root -> right = NULL;
        return true;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        forest.push_back(root);
        for(int i = 0;i < to_delete.size();i++){
            vector<TreeNode*> add_list;
            for(vector<TreeNode*>::iterator it = forest.begin(); it != forest.end();){
                bool deleteRootResult = deleteOneNumber(forest, add_list, *it, to_delete[i]);
                if(deleteRootResult == false) it = forest.erase(it);
                else it++;
            }
            forest.insert(forest.end(), add_list.begin(), add_list.end());
        }
        return forest;
    }
};
