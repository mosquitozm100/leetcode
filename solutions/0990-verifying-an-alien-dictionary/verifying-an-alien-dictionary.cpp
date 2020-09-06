// In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.
//
// Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.
//  
// Example 1:
//
//
// Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
// Output: true
// Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
//
//
// Example 2:
//
//
// Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
// Output: false
// Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
//
//
// Example 3:
//
//
// Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
// Output: false
// Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
//
//
//  
// Constraints:
//
//
// 	1 <= words.length <= 100
// 	1 <= words[i].length <= 20
// 	order.length == 26
// 	All characters in words[i] and order are English lowercase letters.
//
//


class Solution {
public:
    bool compare(string & a, string & b, string & order) { // true is <, false is >=
        for(int i = 0;i < min(a.size(), b.size());i++){
            if(order.find(a[i]) < order.find(b[i])) return true;
            else if(order.find(a[i]) > order.find(b[i])) return false;
        }
        return a.size() < b.size();
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        for(int i = 1;i < n;i++){
            if(compare(words[i - 1], words[i], order) == false) return false;
        }
        return true;
    }
};
