class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    void bfs(int i, vector<int> adj[], vector<int> &vis, bool &cycle) {
        // Code here
        
        queue<pair<int, int>> q;
        vis[i]=1;
        q.push({i, -1});
        
        while(q.size())
        {
            int curr=q.front().first;
            int par=q.front().second;
            q.pop();
            
            for(auto node: adj[curr])
            {
                if(vis[node] and node!=par) 
                {
                    cycle=1;
                    return;
                }
                
                else if(!vis[node])
                {
                    vis[node]=1;
                    q.push({node, curr});
                }
            }
        }
    }
    
    bool isCycle(int n, vector<int> adj[]) 
    {
        // Code here
        vector<int> vis(n,0);
        bool cycle=0;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i]) bfs(i,adj,vis,cycle);
            if(cycle) return 1;
        }
        
        return 0;
    }
};
