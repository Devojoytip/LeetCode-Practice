//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i, int j, int n, int m, vector<vector<int>> v, vector<vector<int>> &dp)
    {
        // code here
        if(i<0 or j<0 or i>=n or j>=m) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j] = v[i][j] + max({f(i,j+1,n,m,v,dp), f(i+1,j+1,n,m,v,dp), f(i-1,j+1,n,m,v,dp)});
    }
    
    int recur(int n, int m, vector<vector<int>> v)
    {
        // code here
        
        int ans=0;
        
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        
        for(int i=0;i<n;i++) dp[i][m-1]=v[i][m-1];
        
        for(int col=m-2;col>=0;col--)
        {
            for(int row=0;row<n;row++)
            {
                int right= dp[row][col+1];
                
                int up_right= (row==0) ? 0 : dp[row-1][col+1];
                
                int down_right= (row==n-1) ? 0 : dp[row+1][col+1];
                
                dp[row][col]=v[row][col]+max({right, up_right, down_right});
            }
        }
        
        for(int i=0;i<n;i++)
        {
            ans=max(ans, dp[i][0]);
        }
        
        return ans;
    }
    
    int maxGold(int n, int m, vector<vector<int>> v)
    {
        // vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        // int ans=0;
        
        // for(int i=0;i<n;i++)
        // {
        //     ans=max(ans, f(i,0,n,m,v,dp));
        // }
        
        // return ans;
        
        return recur(n,m,v);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends