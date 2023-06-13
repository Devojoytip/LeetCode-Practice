//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int a[], int m, int v) 
	{ 
	    // Your code goes here
	    vector<int> dp(v+1,INT_MAX);
	    dp[0]=0;
	    
	    for(int i=1;i<=v;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            int rem=i-a[j];
	            if(rem>=0 and dp[rem]!=INT_MAX and dp[i]>dp[rem]+1) dp[i]= dp[rem]+1;
	        }
	    }
	    return (dp[v]==INT_MAX) ? -1 : dp[v];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends