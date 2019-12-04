// Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.
//
//  
// Example 1:
//
//
// Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
// Output: 9
//
//
// Example 2:
//
//
// Input: grid = [[1,1,0,0]]
// Output: 1
//
//
//  
// Constraints:
//
//
// 	1 <= grid.length <= 100
// 	1 <= grid[0].length <= 100
// 	grid[i][j] is 0 or 1
//


class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size(), n = grid[0].size();
        int pre_sum[m][n][2];    //0 is left -> right, 1 is right -> left
        memset(pre_sum,0,sizeof(pre_sum));
        //pre_sum[0][0][0] = pre_sum[0][0][1] = grid[0][0];
        for(int i =0; i < m;i++){
            for(int j =0; j < n;j++){
                pre_sum[i][j][0] = (j == 0 ? 0 : pre_sum[i][j - 1][0]) + grid[i][j];
                pre_sum[i][j][1] = (i == 0 ? 0 : pre_sum[i - 1][j][1]) + grid[i][j];
                //printf( "%d\t",pre_sum[i][j][0]);
            }
            //puts("");
        }
        int ans = 0;
        for(int i = 0;i < m;i++)   if(grid[i][0] == 1) ans = 1;
        for(int j = 0;j < n;j++)    if(grid[0][j] == 1) ans = 1;
        for(int i1 = 0; i1 < m;i1++){
            for(int j1 = 0;j1 < n;j1++){
                for(int i2 = i1;i2 < m;i2++){
                    for(int j2 = j1;j2 < n;j2++){
                        if(j2 - j1 != i2 - i1) continue;
                        //printf("j1 : %d, j2 : %d, i1 : %d, i2 : %d\n",j1, j2 ,i1,i2);
                        if(pre_sum[i2][j2][0] - (j1 == 0 ? 0 : pre_sum[i2][j1 - 1][0]) != j2 - j1 + 1) continue;
                        if(pre_sum[i2][j2][1] - (i1 == 0 ? 0 : pre_sum[i1 - 1][j2][1]) != i2 - i1 + 1) continue;
                        if(pre_sum[i2][j1][1] - (i1 == 0 ? 0 : pre_sum[i1 - 1][j1][1]) != i2 - i1 + 1) continue;
                        if(pre_sum[i1][j2][0] - (j1 == 0 ? 0 : pre_sum[i1][j1 - 1][0]) != j2 - j1 + 1) continue;
                        ans = max(ans, j2 - j1 + 1);
                    }
                }
            }
        }
        return ans * ans;
    }
};
