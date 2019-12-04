// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// Each number in candidates may only be used once in the combination.
//
// Note:
//
//
// 	All numbers (including target) will be positive integers.
// 	The solution set must not contain duplicate combinations.
//
//
// Example 1:
//
//
// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
//
//
// Example 2:
//
//
// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]
//
//


class Solution {
public:
    void dfs(vector<int> &candidates, int sum, int  target, int last_num_place, vector<int>& combi, vector<vector<int> > &ans){
        if(sum == target) {
            ans.push_back(combi);
        //    for(int i = 0;i < combi.size();i++) printf("%d ", combi[i]);printf("\n");
            return;
        }
        for(int i = last_num_place; i < candidates.size();i++){
            if(sum + candidates[i] <= target){
                combi.push_back(candidates[i]);
                dfs(candidates, sum + candidates[i] , target, i + 1, combi, ans);
                combi.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), greater<int>());
        vector<vector<int>> ans;
        vector<int> combi;
        dfs(candidates, 0, target, 0, combi, ans);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
