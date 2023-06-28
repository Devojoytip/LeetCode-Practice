// https://leetcode.com/problems/path-with-maximum-probability

// Dijkstra Algo

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& p, int src, int des) {

        vector<vector<pair<int, double>>> adj(n);

        for(int i=0;i<e.size();i++)
        {
            int u=e[i][0];
            int v=e[i][1];
            double cost=p[i];
            adj[u].push_back({v,cost});
            adj[v].push_back({u,cost});
        }

        priority_queue<pair<double,int>> pq;
        pq.push({1,src});
        vector<double> dis(n,-1);
        dis[src]=1;

        while(!pq.empty())
        {
            auto [currCost, currNode] = pq.top();
            pq.pop();

            for(auto [next, cost] : adj[currNode])
            {
                if(dis[currNode]*cost > dis[next])
                {
                    dis[next]=dis[currNode]*cost;
                    pq.push({dis[next],next});
                }
            }
        }

        return (dis[des]==-1) ? 0 : dis[des];
    }
};
