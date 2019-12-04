// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
//
// You are given a target value to search. If found in the array return true, otherwise return false.
//
// Example 1:
//
//
// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
//
//
// Example 2:
//
//
// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false
//
// Follow up:
//
//
// 	This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
// 	Would this affect the run-time complexity? How and why?
//
//


class Solution {
public:
    #define getIndex(x) ((x + nums.size() - pivot) % nums.size())
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        int pivot = 0;
        int left = 0, right = nums.size() - 1;
        if(nums[right] > nums[left]) pivot = 0;
        else {
            while(left < right && nums[left] == nums[right]) left++;
            if(left != right && nums[left] < nums[right]) {right = left;left = 0;} 
            while(left < right - 1){
                int mid = (left + right) / 2;
                if(nums[mid] > nums[right]) left = mid;
                else right = mid;
            }
            pivot = nums.size() - left - 1;
        }
        left = 0;right = nums.size() - 1;
        //printf("%d\n", getIndex(right));
        if(nums[getIndex(right)] < target) return false;
        else if(nums[getIndex(right)] == target) return true;
        while(left < right - 1){
            int mid = (left + right) / 2;
            if(nums[getIndex(mid)] <= target) left = mid;
            else right = mid;
        }
        if(nums[getIndex(left)] == target) return true;
        else return false;       
    }
};
