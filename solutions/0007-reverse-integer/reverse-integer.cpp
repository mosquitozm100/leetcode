// Given a 32-bit signed integer, reverse digits of an integer.
//
// Example 1:
//
//
// Input: 123
// Output: 321
//
//
// Example 2:
//
//
// Input: -123
// Output: -321
//
//
// Example 3:
//
//
// Input: 120
// Output: 21
//
//
// Note:
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
//


class Solution {
public:
    int reverse(int x) {
        bool flag = 0;
        if(x < 0) {flag = 1;x = -x;}
        int y = 1,ans = 0;
        while(x >0){
            if(ans > ((1 << 31)  - 1 - x % 10)/ 10) return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        if(flag) ans = -ans;
        return ans;
    }
};
