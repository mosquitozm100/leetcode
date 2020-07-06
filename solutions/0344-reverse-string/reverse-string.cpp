// Write a function that reverses a string. The input string is given as an array of characters char[].
//
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
//
// You may assume all the characters consist of printable ascii characters.
//
//  
//
//
// Example 1:
//
//
// Input: ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]
//
//
//
// Example 2:
//
//
// Input: ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]
//
//
//
//


class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size() == 0) return;
        char tmp;
        for(int i = 0;i < s.size();i++){
            int j = s.size() - i - 1;
            if(j <= i) continue;
            tmp = s[i];s[i] = s[j];s[j] = tmp;
        }
    }
};