// Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
//
// Si % Sj = 0 or Sj % Si = 0.
//
// If there are multiple solutions, return any subset is fine.
//
// Example 1:
//
//
//
// Input: [1,2,3]
// Output: [1,2] (of course, [1,3] will also be ok)
//
//
//
// Example 2:
//
//
// Input: [1,2,4,8]
// Output: [1,2,4,8]
//
//
//


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return nums;
        sort(nums.begin(), nums.end());
        vector<int> dp(n + 1, 1);
        vector<int> backLink(n + 1, -1);
        int maxp = 0, maxm = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                if(nums[i] % nums[j] == 0) {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = max(dp[i], dp[j] + 1); 
                        backLink[i] = j;
                    }
                }
            }
            if(dp[i] > maxm) {
                maxm = dp[i];
                maxp = i;
            }
        }
        
        vector<int> ans;
        while(maxp != -1){
            ans.push_back(nums[maxp]);
            maxp = backLink[maxp];
        } 
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
