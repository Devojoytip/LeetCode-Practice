//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    
    long f(int a[], int n, int s, int e, vector<vector<long>> &dp){
        // Your code here
        if(s>e) return 0;

        if(dp[s][e]!=-1) return dp[s][e];

        long takeFirst = a[s]+min(f(a,n,s+2,e,dp), f(a,n,s+1,e-1,dp));
        
        long takeLast = a[e]+min(f(a,n,s,e-2,dp), f(a,n,s+1,e-1,dp));
        
        return dp[s][e] = max(takeFirst, takeLast);
    }
    
    long long maximumAmount(int a[], int n){
        // Your code here
        vector<vector<long>> dp(n+1, vector<long>(n+1, -1));
        return f(a,n,0,n-1,dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends