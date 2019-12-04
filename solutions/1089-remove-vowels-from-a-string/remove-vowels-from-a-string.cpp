// Given a string S, remove the vowels 'a', 'e', 'i', 'o', and 'u' from it, and return the new string.
//
//  
//
// Example 1:
//
//
// Input: "leetcodeisacommunityforcoders"
// Output: "ltcdscmmntyfrcdrs"
//
//
// Example 2:
//
//
// Input: "aeiou"
// Output: ""
//
//
//  
//
// Note:
//
//
// 	S consists of lowercase English letters only.
// 	1 <= S.length <= 1000
//
//


class Solution {
public:
    string removeVowels(string S) {
        string ans;
        for(int i = 0; i < S.length();i++){
            if(S[i] == 'a' or S[i] == 'e' or S[i] == 'i' or S[i] == 'o' or S[i] == 'u') continue;
            else ans = ans + S[i];
        }
        return ans;
    }
};
