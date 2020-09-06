// Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
//
// Each person may dislike some other people, and they should not go into the same group. 
//
// Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
//
// Return true if and only if it is possible to split everyone into two groups in this way.
//
//  
//
//
//
//
//
//
//
//
//
// Example 1:
//
//
// Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
// Output: true
// Explanation: group1 [1,4], group2 [2,3]
//
//
//
// Example 2:
//
//
// Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
// Output: false
//
//
//
// Example 3:
//
//
// Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
// Output: false
//
//
//
//
//
//  
// Constraints:
//
//
// 	1 <= N <= 2000
// 	0 <= dislikes.length <= 10000
// 	dislikes[i].length == 2
// 	1 <= dislikes[i][j] <= N
// 	dislikes[i][0] < dislikes[i][1]
// 	There does not exist i != j for which dislikes[i] == dislikes[j].
//


class Solution {
public:
    
    bool dfs(vector<int> & colors, vector<vector<int> > & G, int node, int curcolor){
        colors[node] = curcolor;
        for(int i = 0;i < G[node].size(); i++){
            int e = G[node][i];
            if(colors[e] == curcolor) 
                return false;
            else if(colors[e] == 0) 
                if(!dfs(colors, G, e, -curcolor)) 
                    return false;
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> colors(N + 1, 0);
        vector<vector<int> > G(N + 1, vector<int>(0, 0));
        for(int i = 0;i < dislikes.size();i++){
            G[dislikes[i][0]].push_back(dislikes[i][1]);
            G[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        for(int i = 1;i <= N;i++){
            if(colors[i] == 0) 
                if(!dfs(colors, G, i, 1))
                    return false;
        }
        return true;
    }
};
