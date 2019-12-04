// Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly K.
//
// (For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)
//
// Return the number of good subarrays of A.
//
//  
//
// Example 1:
//
//
// Input: A = [1,2,1,2,3], K = 2
// Output: 7
// Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
//
//
// Example 2:
//
//
// Input: A = [1,2,1,3,4], K = 3
// Output: 3
// Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
//
//
//  
//
// Note:
//
//
// 	1 <= A.length <= 20000
// 	1 <= A[i] <= A.length
// 	1 <= K <= A.length
//


class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int ans = 0;
        int left_end = 0;
        int latest =  -1;
        unordered_map<int, int> mp;
        for(int i = 0;i < A.size();i++){
            mp[A[i]] = i;
            if(mp.size() < K){
                continue;
            }else if(mp.size() == K){
                if(latest == -1 || A[latest] == A[i]) {
                    latest = i;
                    for(auto & it: mp) latest = min(latest, it.second);
                }
                ans = ans + (latest - left_end + 1);
            }else if(mp.size() > K){
                left_end = latest + 1;
                mp.erase(A[latest]);
                latest = i;
                for(auto & it: mp) latest = min(latest, it.second);
                ans = ans + (latest - left_end + 1);
            }
            //printf("ans: %d\n", ans);
        }
        return ans;
    }
};
