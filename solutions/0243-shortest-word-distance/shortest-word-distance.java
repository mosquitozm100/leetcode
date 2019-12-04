// Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
//
// Example:
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//
//
// Input: word1 = “coding”, word2 = “practice”
// Output: 3
//
//
//
// Input: word1 = "makes", word2 = "coding"
// Output: 1
//
//
// Note:
// You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
//


class Solution {
    public int shortestDistance(String[] words, String word1, String word2) {
        int pword1 = -1, pword2 = -1;
        int ans = words.length;
        for(int i = 0;i < words.length;i++){
            if(words[i].equals(word1)) {
                pword1 = i;
                if(pword2 != -1) ans = Math.min(ans, pword1 - pword2);
            }else if(words[i].equals(word2)){
                pword2 = i;
                if(pword1 != -1) ans = Math.min(ans, pword2 - pword1);
            }
        }
        if(ans == words.length) return -1;
        else return ans;
    }
}
