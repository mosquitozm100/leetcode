// A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
//
//
// Given a non-empty string containing only digits, determine the total number of ways to decode it.
//
// Example 1:
//
//
// Input: "12"
// Output: 2
// Explanation: It could be decoded as "AB" (1 2) or "L" (12).
//
//
// Example 2:
//
//
// Input: "226"
// Output: 3
// Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
//


class Solution {
public:
    int numDecodings(string s) {
        int lens = s.length();
        int dp[lens + 1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        
        unordered_set<string> u_set;
        for(int i = 1;i <= 26 ;i++){
            u_set.insert(to_string(i));
        }
        for(int i = 1;i <= lens;i++){
            for(int j = max(0, i - 2);j < i;j++){
                if(u_set.count(s.substr(j, i - j))) dp[i] += dp[j];
            }        
        }
        return dp[lens];
    }
};
