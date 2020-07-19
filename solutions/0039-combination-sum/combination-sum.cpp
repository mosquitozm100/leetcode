// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// The same repeated number may be chosen from candidates unlimited number of times.
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
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
//
//
// Example 2:
//
//
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]
//
//
//  
// Constraints:
//
//
// 	1 <= candidates.length <= 30
// 	1 <= candidates[i] <= 200
// 	Each element of candidate is unique.
// 	1 <= target <= 500
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
            int j = 1;
            while(sum + j * candidates[i] <= target){
                combi.push_back(candidates[i]);
                dfs(candidates, sum + j * candidates[i] , target, i + 1, combi, ans);
                j++;
            }
            while(j-- > 1) combi.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), greater<int>());
        vector<vector<int>> ans;
        vector<int> combi;
        dfs(candidates, 0, target, 0, combi, ans);
        return ans;
    }
};
