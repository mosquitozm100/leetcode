// Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.
//
// Examples:
//
//
// s = "leetcode"
// return 0.
//
// s = "loveleetcode"
// return 2.
//
//
//  
//
// Note: You may assume the string contains only lowercase English letters.
//


class Solution {
public:
    int firstUniqChar(string s) {
        int ans = 1e9 + 7;
        unordered_map<char, int> u_map;
        for(int i = s.size() - 1; i >= 0;i--){
            if(!u_map.count(s[i])) u_map[s[i]] = i;
            else u_map[s[i]] = 1e9+7;
            //printf("%d  %d\n",i,u_map[s[i]]);
        }
        for(char i = 'a'; i <= 'z' ;i++){
            if(u_map.count(i)) ans = min(ans, u_map[i]);
        }
        if(ans == 1e9 + 7) return -1;
        else return ans;
    }
};
