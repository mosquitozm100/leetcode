// Given a string, sort it in decreasing order based on the frequency of characters.
//
// Example 1:
//
// Input:
// "tree"
//
// Output:
// "eert"
//
// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
//
//
//
// Example 2:
//
// Input:
// "cccaaa"
//
// Output:
// "cccaaa"
//
// Explanation:
// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.
//
//
//
// Example 3:
//
// Input:
// "Aabb"
//
// Output:
// "bbAa"
//
// Explanation:
// "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.
//
//


class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(int i = 0;i < s.size();i++) {
            if(!mp.count(s[i])) mp[s[i]] = 1;
            else mp[s[i]]++;
        }
        vector<pair<char, int> > cnt(mp.begin(), mp.end());
        sort(cnt.begin(), cnt.end(), 
            [](pair<char, int> & a,pair<char, int> & b){
                return a.second > b.second;
            });
        string ans = "";
        for(int i = 0;i < cnt.size();i++){
            ans.append(cnt[i].second, cnt[i].first);
        }
        return ans;
    }
};
