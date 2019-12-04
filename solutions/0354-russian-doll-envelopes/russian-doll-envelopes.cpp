// You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
//
// What is the maximum number of envelopes can you Russian doll? (put one inside other)
//
// Note:
// Rotation is not allowed.
//
// Example:
//
//
//
// Input: [[5,4],[6,4],[6,7],[2,3]]
// Output: 3 
// Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
//
//
//


class Solution {
public:
    bool static cmp(vector<int> &a, vector<int> &b){
        return a[0] > b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size() == 0) return 0;
        sort(envelopes.begin(), envelopes.end(), cmp);
        int n = envelopes.size();
        vector<int> dp(n + 1, 0);
        int ans = 0;
        for(int i = 0;i < n;i++){
            dp[i] = 1;
            for(int j = 0;j <= i - 1;j++){
                if(envelopes[j][0] > envelopes[i][0] && envelopes[j][1] > envelopes[i][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
            //printf("dp[%d]:%d\n",i,dp[i]);
        }
        return ans;
    }
};
