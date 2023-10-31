//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool isInterleave(string a, string b, string c) 
    {
        //Your code here
        int n=a.size(),m=b.size(),len=c.size();
        if(n+m!=len) return 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(a,n,b,m,c,len,dp);
    }
    
    bool f(string a, int n, string b, int m, string c, int len, vector<vector<int>> &dp) 
    {
        if(len==0) return 1;
        
        if(dp[n][m]!=-1) return dp[n][m];
        
        int amatch=0, bmatch=0;
        
        if(n-1>=0 and a[n-1]==c[len-1]) amatch=f(a,n-1,b,m,c,len-1,dp);
        if(m-1>=0 and b[m-1]==c[len-1]) bmatch=f(a,n,b,m-1,c,len-1,dp);
        
        return dp[n][m]=amatch or bmatch;
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