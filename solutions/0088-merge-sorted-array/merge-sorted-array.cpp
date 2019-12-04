// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//
// Note:
//
//
// 	The number of elements initialized in nums1 and nums2 are m and n respectively.
// 	You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
//
//
// Example:
//
//
// Input:
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3
//
// Output: [1,2,2,3,5,6]
//


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m + n;
        int rear1 = m - 1, rear2 = n - 1;
        for(int i = len - 1;i >= 0;i--){
            if(rear2 <= -1) return;
            if(rear1 <= -1 || nums1[rear1] <= nums2[rear2]) nums1[i] = nums2[rear2--];
            else nums1[i] = nums1[rear1--];
        }
        return;
    }
};
