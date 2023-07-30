
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int n, int curr, vector<int> &vis, vector<int> &path, vector<int> adj[]) {
        
        if(vis[curr] and path[curr]) return 1;
        
        if(vis[curr] and !path[curr]) return 0;
        
        vis[curr]=1;
        path[curr]=1;
        
        for(auto neigh: adj[curr])
        {
            if(dfs(n,neigh,vis,path,adj)) return 1;
        }
        
        path[curr]=0;
        
        return 0;
    }
    
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        vector<int> vis(n,0);
        vector<int> path(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i]) 
            {
                if(dfs(n,i,vis,path,adj)) return 1;
            }
        }
        
        return 0;
    }
};
