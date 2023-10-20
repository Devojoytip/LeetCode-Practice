//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int e, int f) 
    {
        // your code here
        vector<vector<int>> dp(e+1, vector<int>(f+1, -1));
        return func(e,f,dp);
    }
    
    int func(int e, int f, vector<vector<int>> &dp) 
    {
        // your code here
        if(e==1) return f;
        
        if(f<=1) return f;
        
        if(dp[e][f]!=-1) return dp[e][f];
        
        int ans=1e9;
        
        for(int k=1;k<=f;k++) ans=min(ans, 1+max(func(e-1,k-1,dp), func(e,f-k,dp)));
        
        return dp[e][f]=ans;
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