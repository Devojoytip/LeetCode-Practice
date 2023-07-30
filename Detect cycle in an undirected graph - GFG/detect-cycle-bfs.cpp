//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    void bfs(int n, int curr, int parent, bool &cycle, vector<int> adj[], vector<int> &vis)
    {
        queue<pair<int,int>> q;
        q.push({curr,-1});
        vis[curr]=1;
        
        while(q.size())
        {
            int curr=q.front().first;
            int par=q.front().second;
            q.pop();
            
            for(auto neigh: adj[curr])
            {
                if(vis[neigh] and neigh!=par)
                {
                    cycle=1;
                    return;
                }
                
                else if(!vis[neigh])
                {
                    vis[neigh]=1;
                    q.push({neigh,curr});
                }
                
                else continue;
            }
        }
    }
    
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        vector<int> vis(n,0);
        bool cycle=0;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i]) bfs(n,i,-1,cycle,adj,vis);
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
