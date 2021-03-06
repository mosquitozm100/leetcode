// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.
//
// If the last word does not exist, return 0.
//
// Note: A word is defined as a maximal substring consisting of non-space characters only.
//
// Example:
//
//
// Input: "Hello World"
// Output: 5
//
//
//  
//


class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s == "") return 0;
        while(s[s.size() - 1] == ' ') s.pop_back();
        reverse(s.begin(), s.end());
        if(s.find(' ') == -1) return s.length();
        else return s.find(' ');
    }
};
