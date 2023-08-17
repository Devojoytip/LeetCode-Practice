//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
// 	int f(int n, int x, int y, bool g, vector<vector<int>> &dp)
// 	{
// 		// Your code goes here
// 		if(n==0 and g) return 0;
        
// 		if((n==1 or n==x or n==y) and !g) return 0;
        
// 		if((n==1 or n==x or n==y) and g) return 1;
        
// 		if(n==0 and !g) return 1;
		
// 		if(dp[n][g]!=-1) return dp[n][g];
		
// 		bool pickX=0, pickY=0, pickOne=0;

//         if(x<=n) pickX=f(n-x,x,y,!g,dp);
//         if(y<=n) pickY=f(n-y,x,y,!g,dp);
//         pickOne=f(n-1,x,y,!g,dp);
        
// 		return dp[n][g]=pickX and pickY and pickOne;
// 	}
// 	int findWinner(int n, int x, int y)
// 	{
// 		// Your code goes here
//         vector<vector<int>> dp(n+1, vector<int>(2, -1));
//         return f(n,x,y,1,dp);
// 	}

	int findWinner(int n, int x, int y)
	{
		// Your code goes here
        vector<bool> dp(n+1, 0);
        dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            if(i-1>=0 and !dp[i-1]) dp[i]=1; 
            else if(i-x>=0 and !dp[i-x]) dp[i]=1; 
            else if(i-y>=0 and !dp[i-y]) dp[i]=1; 
        }
        
        return dp[n];
	}

};
	

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n, x, y;
       	cin >> n >> x >> y;

       

        Solution ob;
        cout << ob.findWinner(n, x, y);
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends