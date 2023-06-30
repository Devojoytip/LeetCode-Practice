// https://practice.geeksforgeeks.org/problems/check-for-subsequence4930/1

// return LCS(b,a) == a.size() ie LCS is a itself

class Solution{
    public:
    bool isSubSequence(string a, string b) 
    {
        // code here
        
        int n=b.size(), m=a.size();
        if(n<m) return 0;
        
        int dp[n+1][m+1];
        memset(dp,0,sizeof dp);
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(b[i-1]==a[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        
        return dp[n][m] == a.size();
    } 
};
