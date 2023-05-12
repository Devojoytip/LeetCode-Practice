//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    void dfs(vector<int> adj[],vector<bool>&vis,int curr,int parent,bool &cycle)
    {
        vis[curr]=1;
        queue<pair<int,int>>q;
        for(auto neigh:adj[curr]) 
        {
            if(vis[neigh] and neigh!=parent)
            {
                cycle=1;
                break;
            }
            else if(!vis[neigh]) dfs(adj,vis,neigh,curr,cycle);
        }
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>vis(V,0);
        bool cycle=0;
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i]) dfs(adj,vis,i,-1,cycle);
            if(cycle) return 1;
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends