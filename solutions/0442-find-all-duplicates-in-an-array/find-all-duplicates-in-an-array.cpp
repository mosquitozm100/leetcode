// Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
//
// Find all the elements that appear twice in this array.
//
// Could you do it without extra space and in O(n) runtime?
//
// Example:
//
// Input:
// [4,3,2,7,8,2,3,1]
//
// Output:
// [2,3]
//


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int mod = nums.size() + 1;
        nums.push_back(0);
        for(int i = 0;i < nums.size() - 1;i++){
            int x = nums[i] % mod;
            nums[x] += mod;
        }
        int front = 0;
        for(int i = 1;i <nums.size();i++){
            if(nums[i] / mod == 2) nums[front++] = i;
        }
        nums.resize(front);
        return nums;
    }
};
