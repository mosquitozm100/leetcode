// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//
// A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
// Example:
//
//
// X X X X
// X O O X
// X X O X
// X O X X
//
//
// After running your function, the board should be:
//
//
// X X X X
// X X X X
// X X X X
// X O X X
//
//
// Explanation:
//
// Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
//


class Solution {
public:
    struct InQue{
        int x;
        int y;
        
        InQue(int xx, int yy):x(xx), y(yy) {}
    };
    bool isValid(vector<vector<char> > board, vector<vector<bool> >& visited, int x, int y){
        int m = board.size(), n = board[0].size();
        if(x < 0 || y < 0 || x >= m || y >= n) return false;
        if(board[x][y] == 'X') return false;
        if(visited[x][y]) return false;
        return true;
    }
    void BFS(vector<vector<char> > board, vector<vector<bool> >& visited, int i, int j){
        queue<InQue> q;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        q.push(InQue(i, j));
        visited[i][j] = true;
        
        while(!q.empty()){
            InQue e = q.front();q.pop();
            int x = e.x, y = e.y;
            for(int k = 0;k < 4;k++){
                int nx = x + dx[k], ny = y + dy[k];
                if(isValid(board, visited, nx ,ny)){
                    visited[nx][ny] = true;
                    q.push(InQue(nx, ny));
                }
            }
        }
        
        return;
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0) return;
        int n = board[0].size();
        
        vector<vector<bool> > visited(m, vector<bool>(n , false));
        
        for(int i = 0;i < m;i+=max(m - 1, 1)){
            for(int j = 0;j < n;j++){
                if(isValid(board, visited, i ,j)){
                    BFS(board, visited, i, j);
                }
            }
        }
        
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j+= max(1, n - 1)){
                if(isValid(board, visited, i ,j)){
                    BFS(board, visited, i, j);
                }
            }
        }
        
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};
