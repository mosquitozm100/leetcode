// Given a collection of distinct integers, return all possible permutations.
//
// Example:
//
//
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]
//
//


class Solution {
public:
    void recur(vector<int> &nums, int i, vector<vector<int>>& ans){
        if(i == nums.size() - 1){
            ans.push_back(nums);
            return;
        }
        
        for(int k = i; k < nums.size();k++){
            if(i != k && nums[i] == nums[k]) continue;
            swap(nums[i], nums[k]);
            recur(nums, i + 1, ans);
            swap(nums[i],nums[k]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        recur(nums, 0, ans);
        return ans;
    }
};
