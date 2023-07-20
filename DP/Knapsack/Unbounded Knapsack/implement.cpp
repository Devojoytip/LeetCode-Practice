// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

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

class Solution{
public:
    int f(int i, int n, int w, int val[], int wt[], vector<vector<int>> &dp)
    {
        // code here
        if(i==n) return 0;
        
        if(dp[i][w]!=-1) return dp[i][w];
        
        if(w>=wt[i]) dp[i][w] = max(f(i,n,w-wt[i],val,wt,dp)+val[i], f(i+1,n,w,val,wt,dp));
        
        else dp[i][w] = f(i+1,n,w,val,wt,dp);
        
        return dp[i][w];
    }
    
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
        
        return f(0,n,w,val,wt,dp);
    }
};


class Solution{
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(w+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=w;j++)
            {
                if(j>=wt[i-1]) dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][w];
    }
};
