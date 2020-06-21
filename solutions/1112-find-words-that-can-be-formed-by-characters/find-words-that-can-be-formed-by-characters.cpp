// You are given an array of strings words and a string chars.
//
// A string is good if it can be formed by characters from chars (each character can only be used once).
//
// Return the sum of lengths of all good strings in words.
//
//  
//
// Example 1:
//
//
// Input: words = ["cat","bt","hat","tree"], chars = "atach"
// Output: 6
// Explanation: 
// The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
//
//
// Example 2:
//
//
// Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
// Output: 10
// Explanation: 
// The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
//
//
//  
//
// Note:
//
//
// 	1 <= words.length <= 1000
// 	1 <= words[i].length, chars.length <= 100
// 	All strings contain lowercase English letters only.
//


class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        for(int i = 0;i < chars.size();i++){
            if(!mp.count(chars[i])) mp[chars[i]] = 1;
            else mp[chars[i]]++;
        }
        
        unordered_map<char, int> cur;
        int ans = 0;
        for(int i = 0;i < words.size();i++){
            int flag = 1;
            cur.clear();
            for(int j = 0;j < words[i].size();j++){
                if(!cur.count(words[i][j])) cur[words[i][j]] = 1;
                else cur[words[i][j]]++;
                if(!mp.count(words[i][j]) || mp[words[i][j]] < cur[words[i][j]]){
                    flag = 0;
                    break;
                }
            }
            if(flag) ans += words[i].size();
        }
        return ans;
    }
};
