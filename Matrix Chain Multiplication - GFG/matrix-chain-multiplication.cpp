//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[101][101];
    
    int f(int a[], int n, int i, int j)
    {
        // code here
        if(i==j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=1e9;
        
        for(int k=i;k<j;k++)
        {
            ans=min(ans, f(a,n,i,k)+f(a,n,k+1,j)+a[i-1]*a[k]*a[j]);
        }
        
        return dp[i][j]=ans;
    }
    
    int matrixMultiplication(int N, int a[])
    {
        // code here
        memset(dp,-1,sizeof dp);
        return f(a,N,1,N-1);
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