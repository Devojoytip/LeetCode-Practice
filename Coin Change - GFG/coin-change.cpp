//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int v[], int n, int sum) {

        vector<vector<long long>> dp(sum+1, vector<long long>(n, -1));
        
        return f(v,dp,0,n,sum);
    }
    
    long long int f(int v[], vector<vector<long long>>&dp, int i, int n, int sum)
    {
        if(sum==0) return 1;
        
        if(i>=n) return 0;
        
        if(dp[sum][i]!=-1) return dp[sum][i];
        
        long long take=0, notTake=0;
        
        if(v[i]<=sum) take=f(v,dp,i,n,sum-v[i]);
        notTake=f(v,dp,i+1,n,sum);
        
        return dp[sum][i]= take+notTake;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends