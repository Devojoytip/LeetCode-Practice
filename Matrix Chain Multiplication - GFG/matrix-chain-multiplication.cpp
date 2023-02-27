//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[505][505];
    int sol(int i,int j,int arr[])
    {
        if(i>=j)return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int ans=sol(i,k,arr)+sol(k+1,j,arr)+arr[i-1]*arr[j]*arr[k];
            mini=min(mini,ans);
        }
        return dp[i][j]=mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp,-1,sizeof dp);
        return sol(1,N-1,arr);
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