// Given a set of distinct integers, nums, return all possible subsets (the power set).
//
// Note: The solution set must not contain duplicate subsets.
//
// Example:
//
//
// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]
//


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        int maxNum = (1 << len);
        vector<vector<int> > ans;
        for(int num = 0; num < maxNum; num++){
            vector<int>  subset;
            for(int i = 1,j = 0; i < maxNum; i *= 2, j++){
                if(num & i) subset.push_back(nums[j]);
            }
            ans.push_back(subset);
        }
        return ans;
    }
};
