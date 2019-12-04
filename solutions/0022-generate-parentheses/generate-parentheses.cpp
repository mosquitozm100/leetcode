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
    vector<string> ans;
    void dfs(string prefix, int nleft, int nright){
        if(nleft == 0 && nright == 0) {ans.push_back(prefix); return;}
        if(nleft > 0) dfs(prefix + '(', nleft - 1, nright);
        if(nright > 0 && nright - 1 >= nleft) dfs(prefix + ')', nleft, nright - 1);
    }
    vector<string> generateParenthesis(int n) {
        dfs("", n, n);
        return ans;
    }
};
