// Given a m * n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
//
// A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.
//
//  
// Example 1:
//
//
// Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
// Output: [15]
// Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column
//
//
// Example 2:
//
//
// Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
// Output: [12]
// Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
//
//
// Example 3:
//
//
// Input: matrix = [[7,8],[1,2]]
// Output: [7]
//
//
//  
// Constraints:
//
//
// 	m == mat.length
// 	n == mat[i].length
// 	1 <= n, m <= 50
// 	1 <= matrix[i][j] <= 10^5.
// 	All elements in the matrix are distinct.
//


class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size() == 0 || matrix[0].size() == 0) return ans;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int> > mark(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0;i < n;i++){
            int minm = 1000000, p = 0; 
            for(int j = 0;j < m;j++)
                if(matrix[i][j] < minm) {
                    minm = matrix[i][j];
                    p = j;
                }
            mark[i][p]++;
        }
        for(int j = 0;j < m;j++){
            int maxm = 0, p = 0; 
            for(int i = 0;i < n;i++)
                if(matrix[i][j] > maxm) {
                    maxm = matrix[i][j];
                    p = i;
                }
            mark[p][j]++;
            if(mark[p][j] == 2) ans.push_back(matrix[p][j]);
        }
        return ans;
    }
};
