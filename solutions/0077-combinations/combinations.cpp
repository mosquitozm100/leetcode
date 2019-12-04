// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
// Example:
//
//
// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
//
//


class Solution {
public:
    void dfs(int k, vector<int> &tmp, int lastnum, vector<vector<int> > &ans, int n){
        if(k == 0){ans.push_back(tmp);return;}
        for(int i =lastnum + 1;i <= n;i++){
            tmp.push_back(i);
            dfs(k - 1, tmp, i, ans, n);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> tmp;
        dfs(k,tmp, 0,ans,n);
        return ans;
    }
};
