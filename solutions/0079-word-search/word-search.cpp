// Given a 2D board and a word, find if the word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
// Example:
//
//
// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
//
// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.
//
//


class Solution {
public:

    bool dfs(int k, int x, int y, vector<vector<int> > & vis, string &str, int m, int n, vector<vector<char> > board){
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        if(k == str.size()) return true;
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < m && ny >=0 && ny < n && vis[nx][ny] == 0 && str[k] == board[nx][ny]){
                vis[nx][ny] = 1;
                //printf("k:  %d, nx:  %d, ny:  %d\n", k, nx, ny);
                if(dfs(k + 1, nx, ny, vis, str, m ,n, board)) return true;
                vis[nx][ny] = 0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "") return true;
        else if(board.size() == 0 || board[0].size() == 0) return false;
        
        int m = board.size(), n = board[0].size();
        vector<vector<int> > vis;
        for(int i = 0; i < m;i++){
            vis.push_back(vector<int>({}));
            for(int j = 0;j < n;j++){
                vis[i].push_back(0);
            }
        }
        for(int i =0;i < m;i++){
            for(int j = 0; j < n;j++){
                if(board[i][j] != word[0]) continue;
                vis[i][j] = 1;
                //printf("i:  %d, j:  %d\n",i,j);
                if(dfs(1, i, j, vis, word, m, n, board)) return true;
                vis[i][j] = 0;
            }
        }
        return false;
    }
};
