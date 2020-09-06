// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
//
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
//
//  
// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:
// Input: strs = [""]
// Output: [[""]]
// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]
//
//  
// Constraints:
//
//
// 	1 <= strs.length <= 104
// 	0 <= strs[i].length <= 100
// 	strs[i] consists of lower-case English letters.
//
//


class Solution {
public:
    const long long MOD = 1e9 + 7;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int primes[] = {2, 3, 5, 7, 11, 13 ,17, 19, 23, 29, 31, 37, 41, 43, 47 ,53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 103, 107};
        vector<long long > myHash;
        map<long long, vector<int> > myMap;
        vector<vector<string> > ans;
        for(int i = 0; i < strs.size(); i++){
            long long tmp = 1;
            for(int j = 0; j < strs[i].size(); j++){
                if(strs[i][j] == '\0') break;
                tmp = tmp * primes[strs[i][j] - 'a'] % MOD;
            }
            myHash.push_back(tmp);
            myMap[tmp].push_back(i);
        }
        //printf("size:  %d\n" ,myMap.size());
        for(auto it = myMap.begin(); it != myMap.end(); it++){
            vector<string> tmp;
            for(int i =0; i< (*it).second.size();i++){
        //        printf("i: %d\n", i);
        //        cout << strs[(*it).second[i]] << endl;
                tmp.push_back(strs[(*it).second[i]]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
