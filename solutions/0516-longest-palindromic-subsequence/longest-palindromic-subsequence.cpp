//
// Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
//
//
// Example 1:
// Input: 
//
// "bbbab"
//
// Output: 
//
// 4
//
// One possible longest palindromic subsequence is "bbbb".
//
//
// Example 2:
// Input:
//
// "cbbd"
//
// Output:
//
// 2
//
// One possible longest palindromic subsequence is "bb".
//


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int lens = s.length();
        int dp[lens+ 1][lens + 1];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i < lens;i++){
            dp[i][i] = 1;
        }
        for(int lc = 2;lc <= lens;lc++){
            for(int i = 0;i + lc - 1 < lens;i++){
                int j = i + lc  - 1;
                if(s[i] == s[j]) {
                    if(i ==  j - 1) dp[i][j] = 2;
                    else dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][lens - 1];
    }
};
