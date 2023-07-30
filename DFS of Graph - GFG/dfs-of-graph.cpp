//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> res;
    void dfs(int i, vector<int> adj[], vector<int> &vis)
    {
        if(vis[i]) return;
        vis[i]=1;
        res.push_back(i);
        
        for(auto it: adj[i]) 
        {
            if(!vis[it]) dfs(it,adj,vis);
        }
    }
    
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        // Code here
        
        vector<int> vis(n+1,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i]) dfs(i,adj,vis);
        }
        
        return res;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends