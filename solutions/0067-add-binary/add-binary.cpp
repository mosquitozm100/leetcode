// Given two binary strings, return their sum (also a binary string).
//
// The input strings are both non-empty and contains only characters 1 or 0.
//
// Example 1:
//
//
// Input: a = "11", b = "1"
// Output: "100"
//
// Example 2:
//
//
// Input: a = "1010", b = "1011"
// Output: "10101"
//


class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() > b.length()) swap(a,b);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans;
        int flag = 0, i = 0;
        for(i = 0; i < a.length();i++){
            int x = a[i] - '0', y = b[i] - '0';
            int sum = x + y + flag;
            ans += (sum % 2 + '0');
            flag = sum / 2;
        }
        while(i < b.length()){
            int x = b[i] - '0';
            int sum = x + flag ;
            flag = sum / 2;
            ans += (sum % 2 + '0');
            i++;
        }
        if(flag == 1) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
