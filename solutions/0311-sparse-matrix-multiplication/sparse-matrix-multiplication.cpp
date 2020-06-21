// Given two sparse matrices A and B, return the result of AB.
//
// You may assume that A's column number is equal to B's row number.
//
// Example:
//
//
// Input:
//
// A = [
//   [ 1, 0, 0],
//   [-1, 0, 3]
// ]
//
// B = [
//   [ 7, 0, 0 ],
//   [ 0, 0, 0 ],
//   [ 0, 0, 1 ]
// ]
//
// Output:
//
//      |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
// AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
//                   | 0 0 1 |
//
//


class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = B.size(), k = B[0].size();
        
        vector<vector<int> > C(m, vector<int>(k, 0));
        
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(A[i][j] == 0) continue;
                for(int t = 0;t < k;t++){
                    C[i][t] += A[i][j] * B[j][t];
                }
            }
        }
        
        return C;
    }
};
