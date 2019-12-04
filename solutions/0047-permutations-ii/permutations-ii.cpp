// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
// Example:
//
//
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
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
        set<int> s;
        for(int k = i; k < nums.size();k++){
            if(i != k && nums[i] == nums[k]) continue;
            if(s.count(nums[k])) continue;
            s.insert(nums[k]);
            swap(nums[i], nums[k]);
            recur(nums, i + 1, ans);
            swap(nums[i],nums[k]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        recur(nums, 0, ans);
        return ans;
    }
};
