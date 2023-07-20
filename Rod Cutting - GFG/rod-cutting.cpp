//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int f(int price[], int i, int n, vector<vector<int>> &dp) {
        //code here
        
        if(i<0 or n==0) return 0;
        
        if(dp[i][n]!=-1) return dp[i][n];
        
        if(n>=i+1) dp[i][n] = max(f(price,i,n-i-1,dp)+price[i], f(price,i-1,n,dp));
        
        else dp[i][n] = f(price,i-1,n,dp);
        
        return dp[i][n];
    }
    
    int cutRod(int price[], int n) {
        //code here
        
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        
        return f(price,n-1,n,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends