// Write a function to find the longest common prefix string amongst an array of strings.
//
// If there is no common prefix, return an empty string "".
//
// Example 1:
//
//
// Input: ["flower","flow","flight"]
// Output: "fl"
//
//
// Example 2:
//
//
// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
//
//
// Note:
//
// All given inputs are in lowercase letters a-z.
//


class Solution {
public:
    int getCommPre(string a, string  b){
        int ans= 0;
        while(ans < a.length() && ans < b.length() && a[ans] == b[ans]) ans++;
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string nullstr = "";
        if(strs.size() == 0) return nullstr;
        if(strs.size() == 1) return strs[0];
        int ans = strs[0].length();
        for(int i = 0;i < strs.size() - 1;i++){
            ans = min(ans, getCommPre(strs[i], strs[i + 1]));
            if(ans == 0) break;
        }
        if(ans == 0) return nullstr;
        return strs[0].substr(0,ans);
    }
};
