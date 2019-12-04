// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//
// 	Integers in each row are sorted from left to right.
// 	The first integer of each row is greater than the last integer of the previous row.
//
//
// Example 1:
//
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
//
//
// Example 2:
//
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false
//


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int left = 0, right = matrix.size();
        while(left < right - 1){
            int mid = left + (right - left) / 2;
            if(matrix[mid][0] <= target) left = mid;
            else right = mid;
        }
        int row = left;
        
        left = 0, right = matrix[0].size();
        while(left < right - 1){
            int mid = left + (right - left) / 2;
            if(matrix[row][mid] <= target) left = mid;
            else right = mid;
        }
        
        if(matrix[row][left] == target) return true;
        else return false;
    }
};
