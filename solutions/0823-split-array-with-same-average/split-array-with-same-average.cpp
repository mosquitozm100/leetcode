// In a given integer array A, we must move every element of A to either list B or list C. (B and C initially start empty.)
//
// Return true if and only if after such a move, it is possible that the average value of B is equal to the average value of C, and B and C are both non-empty.
//
//
// Example :
// Input: 
// [1,2,3,4,5,6,7,8]
// Output: true
// Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have the average of 4.5.
//
//
// Note:
//
//
// 	The length of A will be in the range [1, 30].
// 	A[i] will be in the range of [0, 10000].
//
//
//  
//


int dp[15 * 10000 + 10][15];
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {        
        int num = A.size() / 2;
        memset(dp,0,sizeof(dp));dp[0][0] = 1;
        for(int i = 0;i < A.size();i++){
            for(int j = num - 1;j >= 1;j--){
                for(int k = 0;k < num * 10000;k++){
                    if(dp[k][j] == 0) continue;
                    if(k + A[i] <= num * 10000) dp[k + A[i]][j + 1] = dp[k][j];
                }
            }
            dp[A[i]][1] = 1;
        }
        int sum = 0;
        for(int i = 0;i < A.size();i++) sum += A[i];
        for(int i = 0;i < num * 10000;i++){
            for(int j = 1;j <= num;j++){
                if(dp[i][j] == 0) continue;
                if(A.size() * i == sum * j) return true;
            }
        }
        return false;
    }
};
