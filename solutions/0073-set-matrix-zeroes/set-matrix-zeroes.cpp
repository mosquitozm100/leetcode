// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
//
// Example 1:
//
//
// Input: 
// [
//   [1,1,1],
//   [1,0,1],
//   [1,1,1]
// ]
// Output: 
// [
//   [1,0,1],
//   [0,0,0],
//   [1,0,1]
// ]
//
//
// Example 2:
//
//
// Input: 
// [
//   [0,1,2,0],
//   [3,4,5,2],
//   [1,3,1,5]
// ]
// Output: 
// [
//   [0,0,0,0],
//   [0,4,5,0],
//   [0,3,1,0]
// ]
//
//
// Follow up:
//
//
// 	A straight forward solution using O(mn) space is probably a bad idea.
// 	A simple improvement uses O(m + n) space, but still not the best solution.
// 	Could you devise a constant space solution?
//
//


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row, col;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0;i < m; i++){
            for(int j = 0; j < n;j++){
                if(matrix[i][j] == 0)   {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for(int i =0; i < row.size();i++){
            for(int j = 0; j < n;j++){
                matrix[row[i]][j] = 0;
            }
        }
        for(int i = 0; i < m;i++){
            for(int j = 0; j < col.size();j++){
                matrix[i][col[j]] = 0;
            }
        }
    }
};
