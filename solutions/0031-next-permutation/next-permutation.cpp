// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//
// The replacement must be in-place and use only constant extra memory.
//
// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
//
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1
//


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int p = nums.size() - 1;
        while(p > 0 && nums[p - 1] >= nums[p]) p--;
        for(int i = p,j = nums.size() - 1.; i < j;i++,j--){
            swap(nums[i],nums[j]);
        }
        if(p == 0) return;
        int k = p;
        while(k < nums.size() - 1 && nums[k] <= nums[p - 1]) k++;
        swap(nums[k], nums[p - 1]);
    }
};
