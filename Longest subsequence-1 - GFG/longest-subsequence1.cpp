//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int f(int v[], int idx, int prev, int n, vector<vector<int>> &dp)
    {
        if(idx==n) return 0;

        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];

        int take = 0, notTake = 0;

        if(prev==-1 or (v[idx] == v[prev]+1 or v[prev] == v[idx]+1)) take = 1 + f(v, idx+1, idx, n, dp);

        notTake = f(v, idx+1, prev, n, dp);

        return dp[idx][prev+1] = max(take, notTake);

    }
    
    int longestSubsequence(int n, int a[])
    {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return f(a,0,-1,n,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends