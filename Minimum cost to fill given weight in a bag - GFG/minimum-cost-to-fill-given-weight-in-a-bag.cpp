//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		
	public:
	
	int f(int cost[], int i, int w, vector<vector<int>> &dp) 
	{ 
        // Your code goes here
        if(w==0) return 0;
        
        if(i==0) return 1e9;

        if(dp[i][w]!=-1) return dp[i][w];

        int take=INT_MAX, notTake=INT_MAX;
        
        if(i<=w and cost[i-1]!=-1) take=cost[i-1]+f(cost,i,w-i,dp);
        notTake=f(cost,i-1,w,dp);
        
        return dp[i][w]=min(take, notTake);
	} 

    int minimumCost(int cost[], int n, int w) 
	{ 
        // Your code goes here
        vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
        int ans=f(cost,n,w,dp);
        return ans==1e9 ? -1 : ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends