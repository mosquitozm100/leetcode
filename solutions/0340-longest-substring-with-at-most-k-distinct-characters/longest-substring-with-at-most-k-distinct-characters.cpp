// Given a string, find the length of the longest substring T that contains at most k distinct characters.
//
// Example 1:
//
//
//
// Input: s = "eceba", k = 2
// Output: 3
// Explanation: T is "ece" which its length is 3.
//
//
// Example 2:
//
//
// Input: s = "aa", k = 1
// Output: 2
// Explanation: T is "aa" which its length is 2.
//
//
//


class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int left = 0, right = 0;
        unordered_map<char, int> mp;
        bool flag = false;
        int ans = 0;
        
        for(int right = 0;right < s.size();right++){
            if(mp.count(s[right])) {mp[s[right]]++;ans = max(ans, right - left + 1);continue;}
            mp[s[right]] = 1;
            //cout << right << " \t" << mp[s[right]] << endl;
            //cout << mp.size() << endl;
            while(left <= right && mp.size() > k){
                mp[s[left]]--;
                if(mp[s[left]] == 0) mp.erase(s[left]);
                left++;
                //cout << "mp.size():" << mp.size() << endl;
            }
            //cout << "left: " << left << "\tright: " << right << endl;
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};
