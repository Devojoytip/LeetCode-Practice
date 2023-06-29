// https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// Direct LCS Code - Length of supersequence = a.size() + b.size() - LCS(a,b)

class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int LCS(string a, string b)
    {
        int n=a.size(), m=b.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
    
    int shortestCommonSupersequence(string a, string b, int n, int m)
    {
        return n + m - LCS(a,b);
    }
};
