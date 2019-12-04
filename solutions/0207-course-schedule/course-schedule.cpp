// There are a total of n courses you have to take, labeled from 0 to n-1.
//
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
//
// Example 1:
//
//
// Input: 2, [[1,0]] 
// Output: true
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0. So it is possible.
//
// Example 2:
//
//
// Input: 2, [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0, and to take course 0 you should
//              also have finished course 1. So it is impossible.
//
//
// Note:
//
//
// 	The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// 	You may assume that there are no duplicate edges in the input prerequisites.
//
//


class Solution {
public:
    struct Edge{
        int from;
        int to;
        Edge(vector<int> edge):from(edge[1]), to(edge[0]) {}
    };
    vector<Edge> edges;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        int ind[numCourses + 1];
        vector<int> G[numCourses + 1];
        memset(ind, 0, sizeof(ind));
        for(int i = 0 ;i < prerequisites.size();i++){
            edges.push_back(Edge(prerequisites[i]));
            G[edges[i].from].push_back(i);
            ind[edges[i].to]++;
        }
        for(int i = 0;i < numCourses;i++){
            if(ind[i] == 0) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int e = q.front();q.pop();cnt++;
            for(int i = 0;i < G[e].size();i++){
                int to = edges[G[e][i]].to;
                ind[to]--;
                if(ind[to] == 0) q.push(to);
            }
        }
        if(cnt != numCourses) return false;
        else return true;
    }
};
