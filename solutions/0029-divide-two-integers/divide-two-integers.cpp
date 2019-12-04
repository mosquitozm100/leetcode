// Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
//
// Return the quotient after dividing dividend by divisor.
//
// The integer division should truncate toward zero.
//
// Example 1:
//
//
// Input: dividend = 10, divisor = 3
// Output: 3
//
// Example 2:
//
//
// Input: dividend = 7, divisor = -3
// Output: -2
//
// Note:
//
//
// 	Both dividend and divisor will be 32-bit signed integers.
// 	The divisor will never be 0.
// 	Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
//
//


class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) {return INT_MAX;}
        long long did = llabs(dividend), div = llabs(divisor);
        long long ans = 0;
        int sign = (dividend < 0) ^ (divisor < 0) ? 1 : 0;
        while(did >= div){
            long long times = 1, tdiv = div;
            while((tdiv << 1) <=did) {
                tdiv <<= 1;
                times <<= 1;
            }
            ans += times;
            did -= tdiv;;
        }
        if(sign == 1) ans = -ans;
        return ans;
    }
};
