//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  
	int f(int a[], int i, int n, int s, int t, vector<vector<int>> &dp)  { 
	    // Your code goes here
	    
	    if(i==n and s<=t) return s;
	    
	    if(s>t) return -1;
	    
	    if(dp[i][s]!=-1) return dp[i][s];
	    
	    if(s+a[i]<=t) dp[i][s]=max(f(a,i+1,n,s+a[i],t,dp), f(a,i+1,n,s,t,dp));
	    
	    else dp[i][s]=f(a,i+1,n,s,t,dp);
	    
	    return dp[i][s];
	} 
	
	int minDifference(int a[], int n)  { 
	    // Your code goes here
	    
	    int sum=0;
	    for(int i=0;i<n;i++) sum+=a[i];
	    int t=sum/2;
	    
	    vector<vector<int>> dp(n+1, vector<int>(t+1,-1));
	    
	    return sum-2*f(a,0,n,0,t,dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends