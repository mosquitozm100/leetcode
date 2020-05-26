// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
//
//  
//
// Example 1:
//
//
// Input: s1 = "ab" s2 = "eidbaooo"
// Output: True
// Explanation: s2 contains one permutation of s1 ("ba").
//
//
// Example 2:
//
//
// Input:s1= "ab" s2 = "eidboaoo"
// Output: False
//
//
//  
// Constraints:
//
//
// 	The input strings only contain lower case letters.
// 	The length of both given strings is in range [1, 10,000].
//
//


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> ans;
        if(s2.size() < s1.size()) return false;
        vector<int> anag_s2(26, 0);
        vector<int> anag_s1(26, 0);
        for(int i = 0;i < s1.size();i++) {
            anag_s1[s1[i] - 'a']++;
        }
        for(int i = 0;i < s1.size();i++){
            anag_s2[s2[i] - 'a']++;
        }
        if(anag_s2 == anag_s1) ans.push_back(0);
        for(int i = 1;i + s1.size() <= s2.size();i++){//printf("1\n");
            int j = i + s1.size();
            anag_s2[s2[i - 1] - 'a']--;
            anag_s2[s2[j - 1] - 'a']++;
            if(anag_s2 == anag_s1) ans.push_back(i);
        }
        if(ans != vector<int>(0,0)) return true;
        else return false;
    }
};
