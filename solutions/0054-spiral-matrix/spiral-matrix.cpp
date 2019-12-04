// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
// Example 1:
//
//
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
//
//
// Example 2:
//
// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
//


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty()) return ans;
        int dx[] = {0, 1 ,0, -1};
        int dy[] = {1, 0, -1, 0};
        int r = matrix.size(), c = matrix[0].size();
        int vis[r][c];
        memset(vis,0,sizeof(vis));
        int x = 0, y = 0;
        int cnt = r * c, k = 0;
        while(cnt--){
            ans.push_back(matrix[x][y]);
            vis[x][y] = 1;
            if(!cnt) return ans;
            int nx = x + dx[k], ny = y + dy[k];
            if(nx >= 0  && nx < r && ny >= 0 && ny < c && !vis[nx][ny]) {x=  nx; y = ny; continue;}
            else {k = (k + 1)% 4; x = x  + dx[k]; y = y + dy[k];}
        }
        return ans;
    }
};
