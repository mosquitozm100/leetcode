// Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
//
//
// 	Each row must contain the digits 1-9 without repetition.
// 	Each column must contain the digits 1-9 without repetition.
// 	Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
//
//
//
// A partially filled sudoku which is valid.
//
// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
// Example 1:
//
//
// Input:
// [
//   ["5","3",".",".","7",".",".",".","."],
//   ["6",".",".","1","9","5",".",".","."],
//   [".","9","8",".",".",".",".","6","."],
//   ["8",".",".",".","6",".",".",".","3"],
//   ["4",".",".","8",".","3",".",".","1"],
//   ["7",".",".",".","2",".",".",".","6"],
//   [".","6",".",".",".",".","2","8","."],
//   [".",".",".","4","1","9",".",".","5"],
//   [".",".",".",".","8",".",".","7","9"]
// ]
// Output: true
//
//
// Example 2:
//
//
// Input:
// [
//   ["8","3",".",".","7",".",".",".","."],
//   ["6",".",".","1","9","5",".",".","."],
//   [".","9","8",".",".",".",".","6","."],
//   ["8",".",".",".","6",".",".",".","3"],
//   ["4",".",".","8",".","3",".",".","1"],
//   ["7",".",".",".","2",".",".",".","6"],
//   [".","6",".",".",".",".","2","8","."],
//   [".",".",".","4","1","9",".",".","5"],
//   [".",".",".",".","8",".",".","7","9"]
// ]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being 
//     modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
//
//
// Note:
//
//
// 	A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// 	Only the filled cells need to be validated according to the mentioned rules.
// 	The given board contain only digits 1-9 and the character '.'.
// 	The given board size is always 9x9.
//
//


class Solution {
public:
    bool check(vector<int>& nums){
        int vis[10];
        memset(vis,0,sizeof(vis));
        for(int i = 0; i < nums.size();i++){
            if(vis[nums[i]] == 1) return false;
            vis[nums[i]] = 1;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int dx[] = {0,-1,0,1,1,1,0,-1,-1};
        int dy[] = {0,-1,-1,-1,0,1,1,1,0};
        int corex[] = {1,4,7,1,4,7,1,4,7};
        int corey[] = {1,1,1,4,4,4,7,7,7};
        
        for(int i = 0;i < 9; i++){
            vector<int> nums;
            for(int j = 0;j < 9;j++){
                if(board[i][j] != '.') nums.push_back(board[i][j] - '0');
            }
            if(!check(nums)) return false;
            nums.clear();
            for(int j = 0;j < 9;j++){
                if(board[j][i] != '.') nums.push_back(board[j][i] - '0');
            }
            if(!check(nums)) return false;
        }
        
        for(int i = 0;i < 9;i++){
            vector<int> nums;
            for(int j = 0;j < 9;j++){
                int nx = corex[i] + dx[j];
                int ny = corey[i] + dy[j];
                if(board[nx][ny] != '.') nums.push_back(board[nx][ny] - '0');
            }
            if(!check(nums)) return false;
        }
        return true;
    }
};
