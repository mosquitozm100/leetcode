// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.
//
// Follow up: Your solution should run in O(log n) time and O(1) space.
//
//  
// Example 1:
// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:
// Input: nums = [3,3,7,7,10,11,11]
// Output: 10
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 10^5
// 	0 <= nums[i] <= 10^5
//
//


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left + 1< right){
            int mid = (left + right) / 2;
            int cnt = 1,lenleft = 0, lenright = 0;
            if(nums[mid - 1] == nums[mid]) {cnt++;lenleft = mid - 1;}
            else lenleft = mid;
            if(nums[mid + 1] == nums[mid]) {cnt++;lenright = nums.size() - mid - 1;}
            else lenright = nums.size() - mid;
            if(cnt == 1) return nums[mid];
            else if(lenleft & 1) right = mid;
            else left = mid;
            printf("%d\t%d\n", left, right);
        }
        if(left > 0 && nums[left - 1] == nums[left]) return nums[right];
        else return nums[left];
    }
};
