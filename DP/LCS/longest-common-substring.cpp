// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{
    public:
    
    int longestCommonSubstr (string a, string b, int n, int m)
    {
        // your code here
        int ans=0;
        int dp[n+1][m+1];
        memset(dp,0,sizeof dp);
        
        if(n==0 or m==0) return ans;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0;
                
                ans=max(ans,dp[i][j]);
            }
        }
        
        return ans;
    }
};
