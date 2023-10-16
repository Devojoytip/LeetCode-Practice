//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int matrixMultiplication(int n, int a[])
    {
        // code 
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return f(n, a, 1, n-1, dp);
    }
    
    int f(int n, int a[], int i, int j, vector<vector<int>> &dp)
    {
        if(i==j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=1e9;
        
        for(int k=i;k<j;k++)
        {
            ans=min(ans, f(n,a,i,k,dp)+f(n,a,k+1,j,dp)+a[i-1]*a[k]*a[j]);
        }
        
        return dp[i][j]=ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends