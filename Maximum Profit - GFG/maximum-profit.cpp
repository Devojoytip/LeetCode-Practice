//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(int n, int i, int c, int buy, int a[], vector<vector<vector<int>>> &dp)
    {
        if(i==n) return 0;
        
        if(dp[i][c][buy]!=-1) return dp[i][c][buy];
        
        int take=0, notTake=0;
        
        if(buy)
        {
            if(c>0) take=f(n,i+1,c,0,a,dp)-a[i];
            notTake= f(n,i+1,c,buy,a,dp);
        }
        
        else
        {
            take=f(n,i+1,c-1,1,a,dp)+a[i];
            notTake= f(n,i+1,c,buy,a,dp);
        }
        
        return dp[i][c][buy]=max(take, notTake);
    }
    
    int maxProfit(int k, int n, int a[]) {
        // code here
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return f(n,0,k,1,a,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends