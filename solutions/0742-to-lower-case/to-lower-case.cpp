// Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
//
//  
//
//
// Example 1:
//
//
// Input: "Hello"
// Output: "hello"
//
//
//
// Example 2:
//
//
// Input: "here"
// Output: "here"
//
//
//
// Example 3:
//
//
// Input: "LOVELY"
// Output: "lovely"
//
//
//
//


class Solution {
public:
    string toLowerCase(string str) {
        string ans;
        for(int i = 0;i < str.size();i++){
            if(str[i] >= 'A' && str[i] <= 'Z')  ans = ans + (char)(str[i] + 'a' - 'A');
            else ans = ans + str[i];
        }
        return ans;
    }
};
