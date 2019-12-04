// On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.
//
// A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
//
// The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
//
// Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.
//
// Examples:
//
//
// Input: board = [[1,2,3],[4,0,5]]
// Output: 1
// Explanation: Swap the 0 and the 5 in one move.
//
//
//
// Input: board = [[1,2,3],[5,4,0]]
// Output: -1
// Explanation: No number of moves will make the board solved.
//
//
//
// Input: board = [[4,1,2],[5,0,3]]
// Output: 5
// Explanation: 5 is the smallest number of moves that solves the board.
// An example path:
// After move 0: [[4,1,2],[5,0,3]]
// After move 1: [[4,1,2],[0,5,3]]
// After move 2: [[0,1,2],[4,5,3]]
// After move 3: [[1,0,2],[4,5,3]]
// After move 4: [[1,2,0],[4,5,3]]
// After move 5: [[1,2,3],[4,5,0]]
//
//
//
// Input: board = [[3,2,4],[1,5,0]]
// Output: 14
//
//
// Note:
//
//
// 	board will be a 2 x 3 array as described above.
// 	board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].
//
//


class Solution {
public:
    int vis[1000000 + 10];
    
    int encode(vector<vector<int>>& board){
        int ret = 0,p = 1;
        for(int i = 0;i < 2;i++){
            for(int j = 0;j < 3;j++){
                ret += board[i][j] * p;
                p *= 10;
            }
        }
        return ret;
    }
    
    vector<vector<int>> decode(int num){
        vector<vector<int> > board(2, vector<int>(3)); 
        for(int i = 0;i < 2;i++){
            for(int j = 0;j < 3;j++){
                board[i][j]=(num % 10);
                num /= 10;
            }
        }
        return board;
    }
    
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    
    int bfs(vector<vector<int>>& board){
        int tmp = encode(board);
        queue<pair<int,int> > q;
        q.push(make_pair((int)tmp, 0));
        vis[tmp] = 1;
        int _final = 54321;
        int ret = 0;
        while(!q.empty()){
            pair<int,int> t = q.front();q.pop();
            if(t.first == _final) return t.second;
            vector<vector<int>> tmp = decode(t.first);
            int xx = 0,yy = 0;
            for(int i = 0;i < 2;i++){
                for(int j = 0;j < 3;j++){
                    if(tmp[i][j] == 0 ) {xx = i;yy = j;}
                }
            }
            for(int i = 0;i < 4;i++){
                int nx = xx + dx[i], ny = yy + dy[i];
                if(nx < 0 || nx >= 2 || ny < 0 || ny >= 3) continue;
                vector<vector<int>> tp = tmp;
                swap(tp[xx][yy],tp[nx][ny]);
                int num = encode(tp);
                if(vis[num]) continue;
                vis[num] = 1;
                q.push(make_pair(num,t.second + 1));
            }
        }
        return -1;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        memset(vis,0,sizeof(vis));
        int ans = bfs(board);
        return ans;
        
    }
};
