// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination

// Dijkstra Algo

class Solution {
public:

    #define ll long long
    #define mod 1000000007

    int countPaths(int n, vector<vector<int>>& v) {
        
        vector<vector<pair<int,ll>>> adj(n);

        for(auto it: v)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        
        vector<ll> dis(n,LONG_MAX);
        vector<ll> ways(n,0);
        
        pq.push({0,0});
        dis[0]=0;
        ways[0]=1;

        while(!pq.empty())
        {
            auto [cost, curr]=pq.top();
            pq.pop();

            for(auto [next, wt] : adj[curr])
            {
                if(dis[next]>cost+wt)
                {
                    dis[next]=cost+wt;
                    ways[next] = ways[curr];
                    pq.push({dis[next],next});
                }
                else if(dis[next]==cost+wt) 
                {
                    ways[next] = (ways[next]%mod + ways[curr]%mod)%mod;
                }
            }
        }

        return ways[n-1] % mod;
    }
};
