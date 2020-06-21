// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete at most two transactions.
//
// Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
//
// Example 1:
//
//
// Input: [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//              Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
//
// Example 2:
//
//
// Input: [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
//              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
//              engaging multiple transactions at the same time. You must sell before buying again.
//
//
// Example 3:
//
//
// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.
//


class Solution {
public:
    vector<int> getMaxProfitForLeft(vector<int> & prices){
        vector<int> maxLeft(prices.size(), 0);
        int minv = prices[0];
        for(int i = 1;i < prices.size();i++){
            minv = min(minv, prices[i]);
            maxLeft[i] = max(maxLeft[i - 1], prices[i] - minv);
        }
        return maxLeft;
    }
    vector<int> getMaxProfitForRight(vector<int> & prices){
        vector<int> maxRight(prices.size(), 0);
        int maxv = prices[prices.size() - 1];
        for(int i = prices.size() - 2;i >= 0;i--){
            maxv = max(maxv, prices[i]);
            maxRight[i] = max(maxRight[i + 1], maxv - prices[i]);
        }
        return maxRight;
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        vector<int> maxLeft(prices.size(), 0);
        vector<int> maxRight(prices.size(), 0);
        
        maxLeft = getMaxProfitForLeft(prices);        
        maxRight = getMaxProfitForRight(prices);
        
        //for(int i = 0;i < maxRight.size();i++) cout << maxLeft[i] << endl;cout << endl;
        //for(int i = 0;i < maxRight.size();i++) cout << maxRight[i] << endl;
        
        int ans = 0;
        for(int i = 0;i < prices.size() + 1;i++){
            ans = max(ans, (i > 0 ? maxLeft[i - 1] : 0) + (i < prices.size() ? maxRight[i] : 0));
        }
        
        return ans;
    }
};
