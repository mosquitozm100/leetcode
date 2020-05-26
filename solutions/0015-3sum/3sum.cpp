// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
//
//


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for(int i = 0;i < len;i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = len - 1;
            while(j < k){
                while(j < k && nums[i] + nums[j] + nums[k] < 0) j++;
                while(j < k && nums[i] + nums[j] + nums[k] > 0) k--;
                if(j < k && nums[i] + nums[j] + nums[k] == 0) {
                    ans.push_back(vector<int>({nums[i], nums[j], nums[k]}));
                    j++;while(j < k && nums[j] == nums[j - 1]) j++;
                    k--;while(j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }
};
