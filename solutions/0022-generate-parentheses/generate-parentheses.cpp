//
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//
//
// For example, given n = 3, a solution set is:
//
//
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]
//


class Solution {
public:
    void helper(int left_remain, int right_remain, string path, vector<string> &result){
        if(left_remain == 0 && right_remain == 0) {result.push_back(path); return;}
        
        if(left_remain > 0) helper(left_remain - 1, right_remain, path + '(', result);
        
        if(left_remain != right_remain && right_remain > 0) helper(left_remain, right_remain - 1, path + ')', result);
    }
    
    vector<string> generateParenthesis(int n) {
        // write your code here
        vector<string> result;
        
        if(n == 0) return result;
        
        int left_remain = n, right_remain = n;
        
        helper(left_remain, right_remain, "", result);
        
        return result;
    }
};
