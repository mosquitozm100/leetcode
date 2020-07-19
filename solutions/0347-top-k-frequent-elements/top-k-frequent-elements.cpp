// Given a non-empty array of integers, return the k most frequent elements.
//
// Example 1:
//
//
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
//
//
//
// Example 2:
//
//
// Input: nums = [1], k = 1
// Output: [1]
//
//
// Note: 
//
//
// 	You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// 	Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
// 	It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
// 	You can return the answer in any order.
//
//


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(int i = 0;i < nums.size();i++){
            cnt[nums[i]]++;
        }
        priority_queue<pair<int, int> > pq;
        for(auto it : cnt){
            pq.push(make_pair(it.second, it.first));
        }
        vector<int> ans;
        while(k-- > 0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
