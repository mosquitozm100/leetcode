// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
// Note: For the purpose of this problem, we define empty string as valid palindrome.
//
// Example 1:
//
//
// Input: "A man, a plan, a canal: Panama"
// Output: true
//
//
// Example 2:
//
//
// Input: "race a car"
// Output: false
//
//
//  
// Constraints:
//
//
// 	s consists only of printable ASCII characters.
//
//


class Solution {
public:
    bool is_lower(char c){
        return c >= 'a' && c <= 'z';
    }
    bool is_upper(char c){
        return c >= 'A' && c <= 'Z';
    }
    bool is_digit(char c){
        return c >= '0' && c <= '9';
    }
    bool cmp(char a, char b){
        if(is_upper(a)) a = a - 'A' + 'a';
        if(is_upper(b)) b = b - 'A' + 'a';
        return a == b;
    }
    bool is_sth(char a){
        return is_upper(a) || is_lower(a) || is_digit(a); 
    }
    bool isPalindrome(string s) {
        int left = 0, right = s.length() -  1;
        while(left< right){
                //printf("left: %d\n", left);
                //printf("right: %d\n", right);
            while(left < right && !is_sth(s[left])) left++;
            while(left < right && !is_sth(s[right])) right--;
            if(cmp(s[left],s[right]) == false) {
                //printf("left: %d\n", left);
                //printf("right: %d\n", right);
                return false;
            }
            left++;right--;
        }
        return true;
    }
};
