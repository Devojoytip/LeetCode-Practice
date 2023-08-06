//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool valid(int curr, int color, int col[], bool edges[101][101], int m, int n)
    {
        for(int i=0;i<n;i++)
        {
            if((edges[curr][i] or edges[i][curr]) and i!=curr and col[i]==color) return 0;
        }
        return 1;
    }
    
    bool f(int curr, int col[], bool edges[101][101], int m, int n) {
        // your code here
        if(curr==n) return 1;
        
        for(int color=1;color<=m;color++)
        {
            
            if(valid(curr,color,col,edges,m,n))
            {
                col[curr]=color;
                
                if(f(curr+1,col,edges,m,n)) return 1;
                
                col[curr]=0;
            }
        }
        
        return 0;
    }
    
    bool graphColoring(bool edges[101][101], int m, int n) {
        // your code here
        int col[n]={0};
        return f(0,col,edges,m,n);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends