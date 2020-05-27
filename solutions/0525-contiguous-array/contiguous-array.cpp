// Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1. 
//
//
// Example 1:
//
// Input: [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
//
//
//
// Example 2:
//
// Input: [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
//
//
//
// Note:
// The length of the given binary array will not exceed 50,000.
//


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> numOfDiff(nums.size(), 0);
        numOfDiff[0] = (nums[0] == 0 ? 1 : -1);
        for(int i = 1;i < nums.size();i++){
            numOfDiff[i] = numOfDiff[i - 1] + (nums[i] == 0 ? 1 : -1);
        }
        unordered_map<int, int> mp; mp[0] = -1;
        int ans = 0;
        for(int i = 0;i < nums.size();i++){
            if(!mp.count(numOfDiff[i])) mp[numOfDiff[i]] = i;
            else ans = max(ans, i - mp[numOfDiff[i]]);
        }
        return ans;
    }
};
