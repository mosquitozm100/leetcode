// Given a pattern and a string str, find if str follows the same pattern.
//
// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
//
// Example 1:
//
//
// Input: pattern = "abba", str = "dog cat cat dog"
// Output: true
//
// Example 2:
//
//
// Input:pattern = "abba", str = "dog cat cat fish"
// Output: false
//
// Example 3:
//
//
// Input: pattern = "aaaa", str = "dog cat cat dog"
// Output: false
//
// Example 4:
//
//
// Input: pattern = "abba", str = "dog dog dog dog"
// Output: false
//
// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.
//


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> strs;
        string tmp = "";
        for(int i = 0;i < str.size();i++){
            //cout << str[i] << endl;
            if(str[i] == ' '){
                if(tmp != "") {
                    strs.push_back(tmp); 
                    tmp = "";
                }
            }
            else tmp += str[i];
            //cout << tmp << endl;
        }
        if(tmp != "") strs.push_back(tmp);
        //for(int i = 0; i < strs.size();i++) cout << strs[i] << endl;
        if(pattern.size() != strs.size()) return false;
        
        unordered_map<char, string> mpP2S;
        unordered_map<string, char> mpS2P;
        for(int i = 0;i < pattern.size();i++){
            if(!mpP2S.count(pattern[i])) mpP2S[pattern[i]] = strs[i];
            else if(mpP2S[pattern[i]] != strs[i]) return false;
            if(!mpS2P.count(strs[i])) mpS2P[strs[i]] = pattern[i];
            else if(mpS2P[strs[i]] != pattern[i]) return false;
        }
        return true;
    }
};
