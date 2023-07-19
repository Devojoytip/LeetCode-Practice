// https://leetcode.com/problems/coin-change

// Direct Code - Unbounded Knapsack

class Solution {
public:
    int f(int i, int n, int w, vector<int>& v, vector<vector<int>> &dp)
    {
        // code here
        if(w==0) return 0;

        if(i==n) return 1e8;
        
        if(dp[i][w]!=-1) return dp[i][w];
        
        if(w>=v[i]) dp[i][w] = min(1+f(i,n,w-v[i],v,dp), f(i+1,n,w,v,dp));
        
        else dp[i][w] = f(i+1,n,w,v,dp);
        
        return dp[i][w];
    }
    
    int coinChange(vector<int>& v, int t) {
        int n=v.size();
        vector<vector<int>> dp(n+1,vector<int>(t+1,-1));

        return (f(0,n,t,v,dp)>=1e8) ? -1 : f(0,n,t,v,dp);
    }
};


class Solution {
public:
    int coinChange(vector<int>& v, int sum) {

        int n=v.size();
        int dp[n+1][sum+1];
      
        for(int i=1;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=sum;j++) dp[0][j]=INT_MAX-1;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(v[i-1]<=j) dp[i][j]=min(1 + dp[i][j-v[i-1]], dp[i-1][j]);
                else dp[i][j]=dp[i-1][j];
            }
        }

        return (dp[n][sum] != INT_MAX-1) ? dp[n][sum] : -1;
    }
};
