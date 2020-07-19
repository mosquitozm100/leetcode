// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
//
// Example:
//
// Given nums = [-2, 0, 3, -5, 2, -1]
//
// sumRange(0, 2) -> 1
// sumRange(2, 5) -> -1
// sumRange(0, 5) -> -3
//
//
//
// Note:
//
// You may assume that the array does not change.
// There are many calls to sumRange function.
//
//


class NumArray {
public:
    vector<int> preSum;
    NumArray(vector<int>& nums) {
        if(nums.size() == 0) return;
        preSum = vector<int>(nums.size(), 0);
        preSum[0] = nums[0];
        for(int i = 1; i < nums.size();i++){
            preSum[i] = preSum[i - 1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if(i == 0) return preSum[j];
        else return preSum[j] - preSum[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
