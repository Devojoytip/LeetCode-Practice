//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int fn(int e, int f, int dp[][201]) 
    {
        // your code here
        if(f==1 or f==0) return f;
        
        if(e==1) return f;
        
        if(dp[e][f]!=-1) return dp[e][f];
        
        int ans=INT_MAX;
        
        for(int k=1;k<=f;k++)
        {
            int breaks=fn(e-1,k-1,dp);
            
            int NotBreaks=fn(e,f-k,dp);
            
            int maxi=1+max(breaks, NotBreaks);
            
            ans=min(ans,maxi);
        }
        
        return dp[e][f]=ans;
    }
    
    int eggDrop(int e, int f) 
    {
        // your code here
        int dp[201][201];
        memset(dp,-1,sizeof dp);
        return fn(e,f,dp);
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