// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
//
// Note: The algorithm should run in linear time and in O(1) space.
//
// Example 1:
//
//
// Input: [3,2,3]
// Output: [3]
//
// Example 2:
//
//
// Input: [1,1,1,3,3,2,2,2]
// Output: [1,2]
//


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = 0, cnt1 = 0;
        int num2 = 0, cnt2 = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == num1 && cnt1 != 0) cnt1++;
            else if(nums[i] == num2 && cnt2 != 0) cnt2++;
            else if(cnt1 == 0) {num1 = nums[i];cnt1 = 1;}
            else if(cnt2 == 0) {num2 = nums[i];cnt2 = 1;}
            else {cnt1--;cnt2--;}
        }
        vector<int> ans;
        int tmpcnt1 = 0, tmpcnt2 = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == num1) tmpcnt1++;
            if(nums[i] == num2) tmpcnt2++;
        }
        if(tmpcnt1 > nums.size() / 3) ans.push_back(num1);
        if(tmpcnt2 > nums.size() / 3 && num2 != num1) ans.push_back(num2);
        return ans;
    }
};
