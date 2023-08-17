//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    
    bool f(string a, string b, string c, int n, int m, int p, vector<vector<int>> &dp)
    {
        if(p==0) return 1;
        
        if(dp[n][m]!=-1) return dp[n][m];

        bool b1=0, b2=0;

        if(n-1>=0 and a[n-1]==c[p-1]) b1=f(a,b,c,n-1,m,p-1,dp);
        
        if(m-1>=0 and b[m-1]==c[p-1]) b2=f(a,b,c,n,m-1,p-1,dp);
        
        return dp[n][m]=b1 or b2;
    }
    
    bool isInterleave(string a, string b, string c) 
    {
        //Your code here
        int n=a.size(), m=b.size(), p=c.size();
        if(n+m!=p) return 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(a,b,c,n,m,p,dp);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends