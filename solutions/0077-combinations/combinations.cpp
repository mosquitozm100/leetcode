// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
// You may return the answer in any order.
//
//  
// Example 1:
//
//
// Input: n = 4, k = 2
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
// Example 2:
//
//
// Input: n = 1, k = 1
// Output: [[1]]
//
//
//  
// Constraints:
//
//
// 	1 <= n <= 20
// 	1 <= k <= n
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
