// Given a binary tree, write a function to get the maximum width of the given tree. The maximum width of a tree is the maximum width among all levels.
//
// The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.
//
// It is guaranteed that the answer will in the range of 32-bit signed integer.
//
// Example 1:
//
//
// Input: 
//
//            1
//          /   \
//         3     2
//        / \     \  
//       5   3     9 
//
// Output: 4
// Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
//
//
// Example 2:
//
//
// Input: 
//
//           1
//          /  
//         3    
//        / \       
//       5   3     
//
// Output: 2
// Explanation: The maximum width existing in the third level with the length 2 (5,3).
//
//
// Example 3:
//
//
// Input: 
//
//           1
//          / \
//         3   2 
//        /        
//       5      
//
// Output: 2
// Explanation: The maximum width existing in the second level with the length 2 (3,2).
//
//
// Example 4:
//
//
// Input: 
//
//           1
//          / \
//         3   2
//        /     \  
//       5       9 
//      /         \
//     6           7
// Output: 8
// Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).
//
//
//  
// Constraints:
//
//
// 	The given binary tree will have between 1 and 3000 nodes.
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
    struct InQue{
        TreeNode * treenode;
        int index;
        
        InQue(TreeNode * t, int inputIndex):treenode(t), index(inputIndex) {}
    };
    int widthOfBinaryTree(TreeNode* root) {
        queue<InQue> q;
        while((root -> left != NULL && root -> right == NULL)
               || (root -> left == NULL &&  root -> right != NULL)){
            if(root -> left != NULL && root -> right == NULL) root = root -> left;
            if(root -> left == NULL && root -> right != NULL) root = root -> right;
        }
        q.push(InQue(root, 0));
        int ans = 1;
        while(!q.empty()){
            int len = q.size();
            int leastIndex = INT_MAX / 2, mostIndex = 0;
            for(int i = 0;i < len;i++){
                InQue e = q.front();q.pop();
                TreeNode * now = e.treenode; 
                int curIndex = e.index;
                if(now -> left != NULL){
                    int newIndex = curIndex * 2;
                    leastIndex = min(leastIndex, newIndex);
                    mostIndex = max(mostIndex, newIndex);
                    q.push(InQue(now -> left, newIndex));
                }
                if(now -> right != NULL){
                    int  newIndex = curIndex * 2 + 1;
                    leastIndex = min(leastIndex, newIndex);
                    mostIndex = max(mostIndex, newIndex);
                    q.push(InQue(now -> right, newIndex));
                }
            }
            //cout << leastIndex << "\t" << mostIndex << endl;
            ans = max(ans, mostIndex - leastIndex + 1);
        }
        return ans;
    }
};
