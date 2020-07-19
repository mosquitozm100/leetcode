// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
//  
// Example 1:
//
//
// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
//
//
// Example 2:
//
//
// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
//
//


class Solution {
private:
    void findWholeIsland(vector<vector<char> > & grid, vector<vector<int> > & vis, int x, int y){
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        int m = grid.size(), n = grid[0].size();
        vis[x][y] = 1;
        for(int k = 0;k < 4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1' && vis[nx][ny] == 0){
                findWholeIsland(grid, vis, nx, ny);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > vis(m, vector<int>(n, 0));
        int ans = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == '1' && vis[i][j] == 0) {
                    ans++;
                    findWholeIsland(grid, vis, i, j);
                }
            }
        }
        return ans;
    }
};
