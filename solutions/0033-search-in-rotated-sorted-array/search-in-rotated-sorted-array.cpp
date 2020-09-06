// You are given an integer array nums sorted in ascending order, and an integer target.
//
// Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
// If target is found in the array return its index, otherwise, return -1.
//
//  
// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:
// Input: nums = [1], target = 0
// Output: -1
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 5000
// 	-10^4 <= nums[i] <= 10^4
// 	All values of nums are unique.
// 	nums is guranteed to be rotated at some pivot.
// 	-10^4 <= target <= 10^4
//
//


class Solution {
public:
    #define getIndex(x) ((x + nums.size() - pivot) % nums.size())
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int pivot = 0;
        int left = 0, right = nums.size() - 1;
        if(nums[right] > nums[left]) pivot = 0;
        else {
            while(left < right - 1){
                int mid = (left + right) / 2;
                if(nums[mid] > nums[right]) left = mid;
                else right = mid;
            }
            pivot = nums.size() - left - 1;
        }
        left = 0;right = nums.size() - 1;
        if(nums[getIndex(right)] < target) return -1;
        else if(nums[getIndex(right)] == target) return getIndex(right);
        while(left < right - 1){
            int mid = (left + right) / 2;
            if(nums[getIndex(mid)] <= target) left = mid;
            else right = mid;
        }
        if(nums[getIndex(left)] == target) return getIndex(left);
        else return -1;
    }
};
