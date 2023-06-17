// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights) adj[it[0]].push_back({it[1],it[2]});

        queue<pair<int,int>> q;
        q.push({src,0});
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        int stops=0;

        while(k>=0 and !q.empty())
        {
            int n=q.size();

            while(n--)
            {
                auto [curr, cost] = q.front();
                q.pop();

                for(auto it: adj[curr])
                {
                    auto [adj,wt] = it;

                    if(wt+cost<dist[adj]) 
                    {
                        dist[adj]=wt+cost;
                        q.push({adj,dist[adj]});
                    }
                }
            }
            k--;
        }

        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};
