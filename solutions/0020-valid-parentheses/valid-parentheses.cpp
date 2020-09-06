// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
// An input string is valid if:
//
//
// 	Open brackets must be closed by the same type of brackets.
// 	Open brackets must be closed in the correct order.
//
//
//  
// Example 1:
//
//
// Input: s = "()"
// Output: true
//
//
// Example 2:
//
//
// Input: s = "()[]{}"
// Output: true
//
//
// Example 3:
//
//
// Input: s = "(]"
// Output: false
//
//
// Example 4:
//
//
// Input: s = "([)]"
// Output: false
//
//
// Example 5:
//
//
// Input: s = "{[]}"
// Output: true
//
//
//  
// Constraints:
//
//
// 	1 <= s.length <= 104
// 	s consists of parentheses only '()[]{}'.
//
//


class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> mp;
        mp['('] = ')';
        mp['['] = ']';
        mp['{'] = '}';
        for(int i= 0;i < s.size();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') stk.push(s[i]);
            else{
                if(!stk.empty() && mp[stk.top()] == s[i]) stk.pop();
                else return false;
            }
        }
        if(!stk.empty()) return false;
        return true;
    }
};
