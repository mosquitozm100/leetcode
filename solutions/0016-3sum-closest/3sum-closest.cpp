// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
// Example:
//
//
// Given array nums = [-1, 2, 1, -4], and target = 1.
//
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
//


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDiff = abs(nums[0] + nums[1] + nums[2] - target);
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0;i < nums.size();i++){
            int j = i + 1, k = nums.size() - 1;
            while(j < k){
                if(abs(nums[i] + nums[j] + nums[k] - target) < minDiff){
                    ans = nums[i] + nums[j] + nums[k];
                    minDiff = abs(ans - target);
                }
                if(nums[i] + nums[j] + nums[k] - target > 0) k--;
                else j++;
            }
        }
        return ans;
    }
};
