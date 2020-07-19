// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
//
// Example 1:
//
//
// Input: n = 12
// Output: 3 
// Explanation: 12 = 4 + 4 + 4.
//
// Example 2:
//
//
// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.


class Solution {
public:
    int numSquares(int n) {
        if(n == 0) return 0;
        vector<int> dp(n + 1, INT_MAX);dp[0] = 0;
        vector<int> perfectSquareNumbers;
        for(int i = 1;i * i <= n;i++){
            perfectSquareNumbers.push_back(i * i);
        }
        int m = perfectSquareNumbers.size();
        for(int i = 0; i < m;i++){
            for(int j = perfectSquareNumbers[i]; j <= n;j++){
                dp[j] = min(dp[j], dp[j - perfectSquareNumbers[i]] + 1);
            }
        }
        return dp[n];
    }
};
