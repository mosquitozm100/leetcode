// Given a non-empty array of digits representing a non-negative integer, increment one to the integer.
//
// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
//
// You may assume the integer does not contain any leading zero, except the number 0 itself.
//
// Example 1:
//
//
// Input: [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
//
//
// Example 2:
//
//
// Input: [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.
//
//


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size(), tmp = 0;
        reverse(digits.begin(), digits.end());
        while(tmp < len && digits[tmp] + 1 == 10){
            digits[tmp] = 0;
            tmp++;
        }
        if(tmp == len) digits.push_back(1);
        else digits[tmp] += 1;
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
