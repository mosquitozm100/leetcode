// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
//
//
// In Pascal's triangle, each number is the sum of the two numbers directly above it.
//
// Example:
//
//
// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]
//
//


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ans;
        for(int i = 0;i < numRows;i++){
            ans.push_back(vector<int>(0, 0));
            if(i == 0) {ans[i].push_back(1);continue;}
            ans[i].push_back(1);
            for(int j = 1;j < i;j++) ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            ans[i].push_back(1);
        }
        return ans;
    }
};
