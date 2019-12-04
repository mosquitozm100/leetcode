// Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
// Example:
//
//
// Input: 3
// Output:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]
//
//


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int mat[n][n];
        memset(mat,0,sizeof(mat));
        int dy[] = {1, 0, -1, 0};
        int dx[] = {0, 1, 0, -1};
        int x = 0, y = 0,k = 0;
        for(int i = 1;i <= n * n;i++){
            mat[x][y] = i;
            int nx=  x + dx[k], ny = y + dy[k];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && mat[nx][ny] == 0){
                x = nx; y = ny;
            }
            else {
                k = (k + 1) % 4;
                x = x + dx[k];
                y = y + dy[k];
            }
        }
        vector<vector<int> > ans;
        for(int i = 0; i < n;i++){
            vector<int> tmp;
            for(int j = 0; j < n;j++){
                tmp.push_back(mat[i][j]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
