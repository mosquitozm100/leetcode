// Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
//
// Example:
//
//
// Input:  [1,2,3,4]
// Output: [24,12,8,6]
//
//
// Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.
//
// Note: Please solve it without division and in O(n).
//
// Follow up:
// Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
//


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        if(nums.size() == 0) return ans;
        vector<int> pre_product(nums.size(), 1);
        vector<int> post_product(nums.size(), 1);
        for(int i = 0;i < nums.size();i++) 
            pre_product[i] = i == 0 ? nums[i] : nums[i] * pre_product[i - 1];
        ans[nums.size() - 1] = pre_product[nums.size() - 2];
        for(int i = nums.size() - 1;i >= 0;i--)
            post_product[i] = i == nums.size() - 1 ? nums[i] : nums[i] * post_product[i + 1];
        ans[0] = post_product[1];
        for(int i = 1;i < nums.size() - 1;i++){
            ans[i] = pre_product[i - 1] * post_product[i + 1];
        }
        return ans;
        
    }
};
