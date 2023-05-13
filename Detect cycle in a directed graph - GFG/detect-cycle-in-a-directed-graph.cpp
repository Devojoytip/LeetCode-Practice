//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> v[],vector<bool> &vis,vector<bool> &same_path,int node) {
        // code here
        if(vis[node] and same_path[node]) return 1;
        if(vis[node] and !same_path[node]) return 0;
        
        vis[node]=1;
        same_path[node]=1;
        
        for(auto neigh:v[node]) 
        {
            if(dfs(v,vis,same_path,neigh)) return 1;
        }
        
        same_path[node]=0;
        
        return 0;
    }
    bool isCyclic(int n, vector<int> v[]) {
        // code here
        vector<bool> vis(n,0);
        vector<bool> same_path(n,0);
        
        for(int i=0;i<n;i++) 
        {
            if(dfs(v,vis,same_path,i)) return 1;
        }
        
        return 0;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends