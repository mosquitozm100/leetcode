// Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
//
// Example 1:
//
//
// Input:nums = [1,1,1], k = 2
// Output: 2
//
//
//  
// Constraints:
//
//
// 	The length of the array is in range [1, 20,000].
// 	The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
//
//


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<long> preSum(nums.size(), 0);
        unordered_map<long, int> mp;
        mp[0] = 1;
        int ans = 0 ;
        for(int i = 0;i < nums.size();i++){
            preSum[i] = i == 0 ? nums[i] : nums[i] + preSum[i - 1];
            if(mp.count(preSum[i] - k)) 
                ans += mp[preSum[i] - k];
            mp[preSum[i]]++;
        }
        return ans;
    }
};
