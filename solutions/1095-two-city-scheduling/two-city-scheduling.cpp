// There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].
//
// Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.
//
//  
//
// Example 1:
//
//
// Input: [[10,20],[30,200],[400,50],[30,20]]
// Output: 110
// Explanation: 
// The first person goes to city A for a cost of 10.
// The second person goes to city A for a cost of 30.
// The third person goes to city B for a cost of 50.
// The fourth person goes to city B for a cost of 20.
//
// The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
//
//
//  
//
// Note:
//
//
// 	1 <= costs.length <= 100
// 	It is guaranteed that costs.length is even.
// 	1 <= costs[i][0], costs[i][1] <= 1000
//


class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size() / 2;
        if(n == 0) return 0;
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0x3fffffff));
        dp[0][0] = 0;
        
        for(int i = 1;i <= 2 * n;i++){
            for(int j = 0;j <= n && j <= i;j++){
                int k = i - j;
                if(k > n) continue;
                //printf("%d\t%d\t%d\n",i ,j ,k);
                if(k > 0) dp[j][k] = min(dp[j][k], dp[j][k - 1] + costs[i - 1][1]);
                if(j > 0) dp[j][k] = min(dp[j][k], dp[j - 1][k] + costs[i - 1][0]);
            }
        }
        
        return dp[n][n];
    }
};
