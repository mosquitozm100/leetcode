// Given two arrays, write a function to compute their intersection.
//
// Example 1:
//
//
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
//
//
//
// Example 2:
//
//
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
//
//
// Note:
//
//
// 	Each element in the result must be unique.
// 	The result can be in any order.
//
//
//  
//


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> u_set;
        for(int i = 0;i < nums1.size();i++){
            u_set.insert(nums1[i]);
        }
        vector<int> ans;
        unordered_set<int> u_set2;
        for(int i = 0;i < nums2.size();i++){
            if(u_set2.count(nums2[i])) continue;
            u_set2.insert(nums2[i]);
            if(u_set.count(nums2[i])) ans.push_back(nums2[i]);
        }
        return ans;
    }
};
