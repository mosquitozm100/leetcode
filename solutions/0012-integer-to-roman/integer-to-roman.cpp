// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
//
//
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
//
// For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
//
// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
//
//
// 	I can be placed before V (5) and X (10) to make 4 and 9. 
// 	X can be placed before L (50) and C (100) to make 40 and 90. 
// 	C can be placed before D (500) and M (1000) to make 400 and 900.
//
//
// Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
//
// Example 1:
//
//
// Input: 3
// Output: "III"
//
// Example 2:
//
//
// Input: 4
// Output: "IV"
//
// Example 3:
//
//
// Input: 9
// Output: "IX"
//
// Example 4:
//
//
// Input: 58
// Output: "LVIII"
// Explanation: L = 50, V = 5, III = 3.
//
//
// Example 5:
//
//
// Input: 1994
// Output: "MCMXCIV"
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
//


class Solution {
public:
    string intToRoman(int num) {
        string ans;
        if(num >= 1000){
            for(int i = 1;i <= num / 1000;i++){
                ans.push_back('M');
            }
            num %= 1000;
        }
        
        if(num >= 100){
            if(num / 100 == 9) ans.append("CM");
            else if(num /100 == 4) ans.append("CD");
            else if(num / 100 >= 5){
                ans.push_back('D');
                for(int i = 1; i <= num / 100 - 5;i++) ans.push_back('C');
            }
            else {
                for(int i = 1;i <= num / 100;i++) ans.push_back('C');
            }
            num %= 100;
        }
        
        if(num >= 10){
            if(num / 10 == 9) ans.append("XC");
            else if(num /10 == 4) ans.append("XL");
            else if(num / 10 >= 5){
                ans.push_back('L');
                for(int i = 1; i <= num / 10 - 5;i++) ans.push_back('X');
            }
            else {
                for(int i = 1;i <= num / 10;i++) ans.push_back('X');
            }
            num %= 10;
        }
        
        if(num >= 1){
            if(num == 9) ans.append("IX");
            else if(num == 4) ans.append("IV");
            else if(num >= 5) {
                ans.push_back('V');
                for(int i = 1; i<= num - 5;i++) ans.push_back('I');
            }
            else {
                for(int  i =1;i <= num ;i++) ans.push_back('I');
            }
        }
        return ans;
    }
};
