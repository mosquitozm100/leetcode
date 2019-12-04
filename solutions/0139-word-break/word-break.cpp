// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
//
// Note:
//
//
// 	The same word in the dictionary may be reused multiple times in the segmentation.
// 	You may assume the dictionary does not contain duplicate words.
//
//
// Example 1:
//
//
// Input: s = "leetcode", wordDict = ["leet", "code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
//
//
// Example 2:
//
//
// Input: s = "applepenapple", wordDict = ["apple", "pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
//              Note that you are allowed to reuse a dictionary word.
//
//
// Example 3:
//
//
// Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output: false
//
//


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> u_set;
        for(int i = 0;i < wordDict.size();i++){
            u_set.insert(wordDict[i]);
        }
        int dp[s.length() + 1];
        memset(dp,0,sizeof(dp));dp[0] = 1;
        for(int i = 0;i <= s.length();i++){
            for(int j = 0; j < i;j++){
                //cout << s.substr(j,i - j) << endl;
                if(dp[j] == 1 && u_set.count(s.substr(j,i - j))){
                    dp[i] = 1;
                    break;
                }
            }
            //printf("i: %d  dp:  %d\n",i,dp[i]);
        }
        
        return dp[s.length()] == 1;
    }
};
