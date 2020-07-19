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
    void dfs(vector<vector<int> > & ans, vector<int> & nums, int curPlace, vector<int> & tmp){
        if(curPlace >= nums.size()) return;
        dfs(ans, nums, curPlace + 1, tmp);
        tmp.push_back(nums[curPlace]);
        ans.push_back(tmp);
        dfs(ans, nums, curPlace + 1, tmp);
        tmp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> tmp;
        ans.push_back(tmp);
        dfs(ans, nums, 0, tmp);
        return ans;
    }
};
