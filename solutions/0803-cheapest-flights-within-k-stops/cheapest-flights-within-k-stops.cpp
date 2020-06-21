// There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.
//
// Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.
//
//
// Example 1:
// Input: 
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 1
// Output: 200
// Explanation: 
// The graph looks like this:
//
//
// The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
//
//
// Example 2:
// Input: 
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 0
// Output: 500
// Explanation: 
// The graph looks like this:
//
//
// The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
//
//
//  
// Constraints:
//
//
// 	The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
// 	The size of flights will be in range [0, n * (n - 1) / 2].
// 	The format of each flight will be (src, dst, price).
// 	The price of each flight will be in the range [1, 10000].
// 	k is in the range of [0, n - 1].
// 	There will not be any duplicated flights or self cycles.
//
//


class Solution {
public:
    struct InQue{
        int city, stop, cost;
        
        InQue(int curCity, int curStop, int curCost):city(curCity), stop(curStop),cost(curCost) {}
        
        bool operator < (const InQue & b) const {
            return cost > b.cost || cost == b.cost && city < b.city || cost == b.cost && city == b.city && stop < b.stop;
        }
    };
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int> > G(n + 1, vector<int>(0 , 0));
        for(int i = 0;i < flights.size();i++){
            G[flights[i][0]].push_back(i);
        }
        priority_queue<InQue> q;
        q.push(InQue(src, 0, 0));
        set<InQue> vis;
        
        int ans = -1;
        while(!q.empty()){
            InQue e = q.top();q.pop();
            cout << e.city << " " << e.stop << " " << e.cost << endl;
            if(e.city == dst) {ans = e.cost;break;}
            if(vis.count(InQue(e.city, e.stop, 0))) continue;
            vis.insert(InQue(e.city, e.stop, 0));
            int x = e.city, y = e.stop;
            
            if(y > K) continue;
            
            cout << "yes" << endl;
            for(int i = 0;i < G[x].size();i++){
                int toCity = flights[G[x][i]][1];
                int cost = flights[G[x][i]][2];
                cout << toCity << " " << cost << endl;
                if(vis.count(InQue(toCity, y + 1, 0))) continue;
                q.push(InQue(toCity, y + 1, e.cost + cost));
            }
        }
        return ans;
            
    }
};
