//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    int sol(int n, int f, vector<vector<int>> &dp) 
    {
        if(f==0 or f==1) return f;
        
        if(n==1) return f;
        
        if(dp[n][f]!=-1) return dp[n][f];
        
        int ans=1e9;
        for(int k=1;k<=f;k++)
        {
            dp[n][f]=1+max(sol(n-1,k-1,dp), sol(n,f-k,dp));
            ans=min(ans, dp[n][f]);
        }
        
        return dp[n][f]=ans;
    }
    
    int eggDrop(int n, int f) 
    {
        // your code here
        vector<vector<int>> dp(n+1,vector<int>(f+1, -1));
        
        return sol(n,f,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends