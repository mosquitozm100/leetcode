// Numbers can be regarded as product of its factors. For example,
//
//
// 8 = 2 x 2 x 2;
//   = 2 x 4.
//
//
// Write a function that takes an integer n and return all possible combinations of its factors.
//
// Note:
//
//
// 	You may assume that n is always positive.
// 	Factors should be greater than 1 and less than n.
//
//
// Example 1: 
//
//
// Input: 1
// Output: []
//
//
// Example 2: 
//
//
// Input: 37
// Output:[]
//
// Example 3: 
//
//
// Input: 12
// Output:
// [
//   [2, 6],
//   [2, 2, 3],
//   [3, 4]
// ]
//
// Example 4: 
//
//
// Input: 32
// Output:
// [
//   [2, 16],
//   [2, 2, 8],
//   [2, 2, 2, 4],
//   [2, 2, 2, 2, 2],
//   [2, 4, 4],
//   [4, 8]
// ]
//
//


class Solution {
public:
    void dfs(int n, int now_factor, vector<int> &path, vector<vector<int> > &result){
        if(n == 1) {
            if(path.size() <= 1) //防止只返回本身
                return; 
            result.push_back(path);
            return;
        }
        for(int i = now_factor;i < sqrt(n) + 1 && i < n;i++){
            if(n % i == 0){
                path.push_back(i);
                dfs(n / i, i, path, result);
                path.pop_back();
            }
        }
        
        if(n >= now_factor){
            path.push_back(n);
            dfs(1, n, path, result);
            path.pop_back();
        }
        
    }
    
    vector<vector<int>> getFactors(int n) {
        // write your code here
        vector<vector<int> > result;
        vector<int> path;
        
        dfs(n, 2, path, result);
        
        return result;
    }
};
