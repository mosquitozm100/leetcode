// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//
// Example 1:
//
//
// Input: num1 = "2", num2 = "3"
// Output: "6"
//
// Example 2:
//
//
// Input: num1 = "123", num2 = "456"
// Output: "56088"
//
//
// Note:
//
//
// 	The length of both num1 and num2 is < 110.
// 	Both num1 and num2 contain only digits 0-9.
// 	Both num1 and num2 do not contain any leading zero, except the number 0 itself.
// 	You must not use any built-in BigInteger library or convert the inputs to integer directly.
//
//


class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ans(num1.size() + num2.size(), 0);
        const int MOD = 10;
        int carry = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i = 0;i < num1.size();i++){
            int a = num1[i] - '0';carry = 0;
            for(int j = 0;j < num2.size();j++){    
                int b = num2[j] - '0';
                int result = a * b + carry;
                ans[i + j] += result;
                carry = ans[i + j] / 10;
                ans[i + j] %= 10;
            }
            int p = i + num2.size();
            while(carry > 0) {
                ans[p] = ans[p] + carry;
                carry = ans[p] / 10;
                ans[p] %= 10;
                p++;
            }
            //for(int k = ans.size() - 1;k >= 0;k--) printf("%d", ans[k]);printf("\n");
        }
        string ret;
        int index = ans.size() - 1;
        while(index >= 0 && ans[index] == 0) index--;
        if(index == -1) return "0";
        for(int i = index;i >= 0;i--){
            ret = ret + (char)(ans[i] + '0');
        }
        return ret;
    }
};
