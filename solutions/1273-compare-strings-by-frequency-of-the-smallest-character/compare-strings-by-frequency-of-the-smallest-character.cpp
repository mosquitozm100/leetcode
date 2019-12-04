// Let's define a function f(s) over a non-empty string s, which calculates the frequency of the smallest character in s. For example, if s = "dcce" then f(s) = 2 because the smallest character is "c" and its frequency is 2.
//
// Now, given string arrays queries and words, return an integer array answer, where each answer[i] is the number of words such that f(queries[i]) < f(W), where W is a word in words.
//
//  
// Example 1:
//
//
// Input: queries = ["cbd"], words = ["zaaaz"]
// Output: [1]
// Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").
//
//
// Example 2:
//
//
// Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
// Output: [1,2]
// Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").
//
//
//  
// Constraints:
//
//
// 	1 <= queries.length <= 2000
// 	1 <= words.length <= 2000
// 	1 <= queries[i].length, words[i].length <= 10
// 	queries[i][j], words[i][j] are English lowercase letters.
//
//


class Solution {
public:
    int f(string s) { 
        int cnt = 0;
        char minc = 'z';
        for(int i = 0;i < s.size();i++){
            if(s[i] < minc) {minc = s[i]; cnt = 1;}
            else if(s[i] == minc) cnt++;
        }
        return cnt;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> ans;
        int fs[words.size() + 1];
        for(int i = 0;i < words.size();i++){
            fs[i] = f(words[i]);
        }
        sort(fs, fs + words.size());
//        for(int i = 0;i < words.size();i++) printf("%d ", fs[i]);
        for(int i = 0;i < queries.size();i++){
            int num = upper_bound(fs, fs + words.size(), f(queries[i])) - fs;
            ans.push_back(words.size() - num);
        }
        return ans;
    }
};
