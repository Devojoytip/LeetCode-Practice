// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

int LCS(string a,string b,int n)
{
    int dp[n+1][n+1];
    memset(dp,0,sizeof dp);
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i-1]==b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    
    return dp[n][n];
}

int minDeletions(string s, int n) { 
    //complete the function here 
    string t=s;
    reverse(s.begin(),s.end());
    
    return s.size() - LCS(t,s,s.size());
} 
