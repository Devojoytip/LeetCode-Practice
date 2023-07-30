//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    // BFS- Kahn's Algo - Topological Sort
    
    bool isCyclic(int n, vector<int> v[]) {
        // code here
        vector<int> in_degree(n,0);
        vector<int> topo;
        stack<int> s;
        
        for(int i=0;i<n;i++)
        {
            for(auto it:v[i]) in_degree[it]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(in_degree[i]==0) s.push(i);
        }
        
        while(!s.empty())
        {
            int i=s.top();
            s.pop();
            topo.push_back(i);
            
            for(auto it:v[i])
            {
                if(in_degree[it]!=0) in_degree[it]--;
                if(in_degree[it]==0) s.push(it);
            }
        }
        
        return topo.size()<n;
        
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
