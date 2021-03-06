// Given two strings s and t , write a function to determine if t is an anagram of s.
//
// Example 1:
//
//
// Input: s = "anagram", t = "nagaram"
// Output: true
//
//
// Example 2:
//
//
// Input: s = "rat", t = "car"
// Output: false
//
//
// Note:
// You may assume the string contains only lowercase alphabets.
//
// Follow up:
// What if the inputs contain unicode characters? How would you adapt your solution to such case?
//


class Solution {
    public boolean isAnagram(String s, String t) {
        char[] s_char = s.toCharArray();
        char[] t_char = t.toCharArray();
        if(s_char.length != t_char.length) return false;
        int[] cnts = new int[26];
        int[] cntt = new int[26];
        for(int i = 0;i < s_char.length;i++){
            cnts[s_char[i] - 'a']++;
            cntt[t_char[i] - 'a']++;
        }
        for(int i = 0;i < 26;i++) {
            if(cnts[i] != cntt[i]) return false;
        }
        return true;
    }
}
