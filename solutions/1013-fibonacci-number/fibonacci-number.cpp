// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
//
//
// F(0) = 0,   F(1) = 1
// F(N) = F(N - 1) + F(N - 2), for N > 1.
//
//
// Given N, calculate F(N).
//
//  
//
// Example 1:
//
//
// Input: 2
// Output: 1
// Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
//
//
// Example 2:
//
//
// Input: 3
// Output: 2
// Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
//
//
// Example 3:
//
//
// Input: 4
// Output: 3
// Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
//
//
//  
//
// Note:
//
// 0 ≤ N ≤ 30.
//


class Solution {
public:
    const static int MOD = 100000000;
    struct Matrix{
        int m,n;
        vector<vector<int> > mat;
        
        Matrix(int mm, int nn):n(nn),m(mm){
            mat = vector<vector<int> >(m ,vector<int>(n, 0));
        }
        
        Matrix operator * (const Matrix & b) const{
            int k = b.n;
            Matrix ret(m, k);
            for(int i = 0;i < m;i++){
                for(int j = 0;j < k;j++){
                    for(int t = 0;t < n;t++){
                        ret.mat[i][j] += mat[i][t] * b.mat[t][j];
                        ret.mat[i][j] %= MOD;
                    }
                }
            }
            return ret;
        }
    };
    
    Matrix matrixFastPower(Matrix x, int k){
        int len = x.m;
        Matrix ret(len , len);
        for(int i = 0;i < len ;i++) ret.mat[i][i] = 1;
        
        while(k > 0){
            if(k & 1) ret = ret * x;
            x = x * x;
            k >>= 1;
        }
        return ret;
    }
    
    int fib(int N) {
        // write your code here
        Matrix mat(2, 2);
        mat.mat[0][0] = 1; mat.mat[0][1] = 1;
        mat.mat[1][0] = 1; mat.mat[1][1] = 0;
        
        Matrix final = matrixFastPower(mat, N);
        
        return final.mat[0][1];
    }
};
