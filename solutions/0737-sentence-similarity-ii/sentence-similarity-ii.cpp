// Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.
//
// For example, words1 = ["great", "acting", "skills"] and words2 = ["fine", "drama", "talent"] are similar, if the similar word pairs are pairs = [["great", "good"], ["fine", "good"], ["acting","drama"], ["skills","talent"]].
//
// Note that the similarity relation is transitive. For example, if "great" and "good" are similar, and "fine" and "good" are similar, then "great" and "fine" are similar.
//
// Similarity is also symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.
//
// Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.
//
// Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].
//
// Note:
//
//
// 	The length of words1 and words2 will not exceed 1000.
// 	The length of pairs will not exceed 2000.
// 	The length of each pairs[i] will be 2.
// 	The length of each words[i] and pairs[i][j] will be in the range [1, 20].
//
//
//  
//


class Solution {
public:
    int fa[4000 + 10];
    int find(int x) {return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);}
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if(words1.size() != words2.size()) return false;
        vector<string> pairs_strings;
        unordered_map<string, int> u_map;
        for(int i = 0;i < pairs.size();i++){
            for(int j = 0;j < 2;j++){
                if(!u_map.count(pairs[i][j])) {
                    pairs_strings.push_back(pairs[i][j]);
                    u_map[pairs[i][j]] = pairs_strings.size() - 1;
                }
            }
        }
        int scnt = pairs.size();
        for(int i = 0;i < scnt;i++) fa[i] = i;
        for(int i = 0;i < pairs.size();i++){
            int a = u_map[pairs[i][0]], b = u_map[pairs[i][1]];
            int x = find(a), y = find(b);
            if(x != y) fa[x] = y;
        }
        
        for(int i = 0;i < words1.size();i++){
            if(words1[i] == words2[i]) continue;
            if(!u_map.count(words1[i]) || !u_map.count(words2[i])) return false;
            int x = find(u_map[words1[i]]), y = find(u_map[words2[i]]);
            if(x != y) return false;
        }
        return true;
    }
};
