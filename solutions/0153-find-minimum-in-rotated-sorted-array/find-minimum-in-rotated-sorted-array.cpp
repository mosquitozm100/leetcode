// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
//
// Find the minimum element.
//
// You may assume no duplicate exists in the array.
//
// Example 1:
//
//
// Input: [3,4,5,1,2] 
// Output: 1
//
//
// Example 2:
//
//
// Input: [4,5,6,7,0,1,2]
// Output: 0
//
//


class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(nums[0] < nums[n - 1]) return nums[0];
        int left = 0, right = n - 1;
        while(left + 1 < right){
            int mid = (left + right) / 2;
            if(nums[mid] > nums[0]) left = mid;
            else right = mid;
        }
        return nums[right];
    }
};
