// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
//
//
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
//
// Example 2:
//
//
// Input: "cbbd"
// Output: "bb"
//
//


class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 0,len = s.length();
        int p = 0;
        string ret;
        //Odd length
        for(int i = 0;i < len;i++){
            for(int j = 0;j < len;j++){
                int left = i - j, right = i + j;
                if(left < 0 || right >= len) break;
                if(s[left] != s[right]) break;
                if(j * 2 + 1 >ans){
                    ans = max(ans,j * 2 + 1);
                    p = i;
                    ret = s.substr(left,ans);
                }
            }
        }
        
        //Even Length
        for(int  i = 0;i + 1 < len;i++){
            for(int j = 1;j < len;j++){
                int left = i - j + 1, right = i + j;
                if(left < 0 || right >= len) break;
                if(s[left] != s[right]) break;
                if(j * 2  >ans){
                    ans = max(ans,j * 2 );
                    p = i;
                    ret = s.substr(left,ans);
                }
            }            
        }
        return ret;
    }
};
