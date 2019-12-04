// The count-and-say sequence is the sequence of integers with the first five terms as following:
//
//
// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
//
//
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
//
// Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
//
// Note: Each term of the sequence of integers will be represented as a string.
//
//  
//
// Example 1:
//
//
// Input: 1
// Output: "1"
//
//
// Example 2:
//
//
// Input: 4
// Output: "1211"
//


class Solution {
public:
    string countAndSay(int n) {
        string pre = "1", next = "";
        if(n == 1) return  pre;
        n--;
        while(n--){
            char num;
            int times = 0;
            for(int i = 0;i < pre.length();i++){
                if(times == 0) {num = pre[i];times = 1;continue;}
                if(pre[i] != num) {
                    next = next + char(times + '0') + num;
                    num = pre[i];
                    times = 1;
                }
                else times++;
            } 
            next = next + char(times + '0') + num;
            pre = next;
            next = "";
        }
        return pre;
    }
};
