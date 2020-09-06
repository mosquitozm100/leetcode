// Implement pow(x, n), which calculates x raised to the power n (i.e. xn).
//
//  
// Example 1:
//
//
// Input: x = 2.00000, n = 10
// Output: 1024.00000
//
//
// Example 2:
//
//
// Input: x = 2.10000, n = 3
// Output: 9.26100
//
//
// Example 3:
//
//
// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
//
//
//  
// Constraints:
//
//
// 	-100.0 < x < 100.0
// 	-231 <= n <= 231-1
// 	-104 <= xn <= 104
//
//


class Solution {
public:
    double myPow(double x, int n) {
        long nn = n;
        if(nn == 0) return 1;
        if(nn < 0) {x = 1 / x; nn = -nn;}
        double ans = 1;
        while(nn > 0){
            if(nn & 1) ans = ans * x;
            x = x * x;
            nn >>= 1;
        }
        return ans;
    }
};
