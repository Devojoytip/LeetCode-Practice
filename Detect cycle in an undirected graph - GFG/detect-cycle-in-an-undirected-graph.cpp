//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    void bfs(vector<int> adj[],vector<bool>&vis,int curr,bool &cycle)
    {
        queue<pair<int,int>>q;
        q.push({curr,-1});
        
        while(!q.empty())
        {
            int curr=q.front().first;
            int parent=q.front().second;
            vis[curr]=1;
            q.pop();
            for(auto neigh:adj[curr])
            {
                if(!vis[neigh])
                {
                    vis[neigh]=1;
                    q.push({neigh,curr});
                }
                else if(vis[neigh] and parent!=neigh) 
                {
                    cycle=1;
                    break;
                }
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>vis(V,0);
        bool cycle=0;
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i]) bfs(adj,vis,i,cycle);
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