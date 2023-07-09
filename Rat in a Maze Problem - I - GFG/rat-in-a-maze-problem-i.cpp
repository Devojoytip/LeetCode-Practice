//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void recur(vector<vector<int>> &v, vector<string> &res, string curr, int x, int y,int n, map<char, pair<int,int>> mp, vector<vector<int>> vis) {
        // Your code goes here
        
        if(x==n-1 and y==n-1 and v[x][y]==1)
        {
            res.push_back(curr);
            return;
        }
        
        for(auto it : mp)
        {
            char c=it.first;
            pair<int,int> p=it.second;
            
            int dx=p.first;
            int dy=p.second;
            
            int X=x+dx, Y=y+dy;
            
            if(X>=n or Y>=n or X<0 or Y<0 or v[X][Y]==0 or vis[X][Y]==1) continue;
            
            curr.push_back(c);
            vis[X][Y]=1;
            
            recur(v,res,curr,X,Y,n,mp,vis);
            
            // back-tracking
            if(curr.size()) curr.pop_back();
            vis[X][Y]=0;
        }
        
    }
    
    vector<string> findPath(vector<vector<int>> &v, int n) {
        // Your code goes here
        vector<string> res;
        vector<vector<int>> vis(n,vector<int>(n,0));
        string s="";
        
        map<char, pair<int,int>> mp;
        
        mp['R']={0,1};
        mp['L']={0,-1};
        mp['D']={1,0};
        mp['U']={-1,0}; 
        
        if(v[0][0]==0) return res;
        
        vis[0][0]=1;
        
        recur(v,res,s,0,0,n,mp,vis);
        
        return res;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends