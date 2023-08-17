//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	long long getCount(int n)
	{
		// Your code goes here
		vector<vector<int>> v{
            {1,2,3},
            {4,5,6},
            {7,8,9},
            {-1,0,-1}
        };
        
        vector<vector<long>> dp(10, vector<long>(n+1, -1));
        
        long long ans=0;
        
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++) 
            {
                if(v[i][j]!=-1) ans+=f(n,i,j,v,dp);
            }
        }

        return ans;
	}
	
    long long f(int n, int i, int j, vector<vector<int>> v, vector<vector<long>> &dp){
        // Your code here
        if(n==1) return 1;

        if(dp[v[i][j]][n]!=-1) return dp[v[i][j]][n];

        //int up, down, left, right, curr;

        long curr=f(n-1,i,j,v,dp);
        long up= (i-1>=0 and v[i-1][j]!=-1) ? f(n-1,i-1,j,v,dp) : 0;
        long down= (i+1<4 and v[i+1][j]!=-1) ? f(n-1,i+1,j,v,dp): 0;
        long left= (j-1>=0 and v[i][j-1]!=-1) ? f(n-1,i,j-1,v,dp) : 0;
        long right= (j+1<3 and v[i][j+1]!=-1) ? f(n-1,i,j+1,v,dp) : 0;
        
        return dp[v[i][j]][n] = up + down + left + right + curr;
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

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends