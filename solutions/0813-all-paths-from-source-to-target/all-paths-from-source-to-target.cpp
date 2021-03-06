// Given a directed acyclic graph of N nodes. Find all possible paths from node 0 to node N-1, and return them in any order.
//
// The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.
//
//
// Example:
// Input: [[1,2],[3],[3],[]]
// Output: [[0,1,3],[0,2,3]]
// Explanation: The graph looks like this:
// 0--->1
// |    |
// v    v
// 2--->3
// There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
//
//
//  
// Constraints:
//
//
// 	The number of nodes in the graph will be in the range [2, 15].
// 	You can print different paths in any order, but you should keep the order of nodes inside one path.
//
//


class Solution {
public:
    void dfs(vector<vector<int>>& graph, int now, int end, vector<int>& path, vector<vector<int> >& ans){
        if(now == end) {ans.push_back(path);return;}
        for(int i = 0;i < graph[now].size();i++){
            int t = graph[now][i];
            path.push_back(t);
            dfs(graph, t, end, path, ans);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int> > ans;
        vector<int> path;
        path.push_back(0);
        dfs(graph, 0, n - 1, path, ans);
        return ans;
    }
};
