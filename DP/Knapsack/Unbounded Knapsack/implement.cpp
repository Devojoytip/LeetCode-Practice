// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

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
