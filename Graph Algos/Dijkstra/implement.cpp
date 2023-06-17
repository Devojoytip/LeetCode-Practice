// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int src)
    {
        // Code here
        set<pair<int,int>> s;
        vector<int> dist(n,INT_MAX);
        s.insert({0,src});
        dist[src]=0;
        
        while(!s.empty())
        {
            auto curr=*(s.begin());
            int cost=curr.first;
            int vertex=curr.second;
            s.erase(curr);
            
            for(auto edge:adj[vertex])
            {
                if(cost+edge[1]<dist[edge[0]]) 
                {
                    if(dist[edge[0]]!=INT_MAX) s.erase({dist[edge[0]],edge[0]});
                    dist[edge[0]]=cost+edge[1];
                    s.insert({dist[edge[0]],edge[0]});
                }
            }
        }
        
        return dist;
    }
};
