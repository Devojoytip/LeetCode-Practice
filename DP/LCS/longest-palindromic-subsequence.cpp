// https://leetcode.com/problems/longest-palindromic-subsequence/

// LPS = LCS(s, reverse of s)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        string a=s;
        reverse(s.begin(),s.end());
        string b=s;
        int n=s.length();
        int dp[n+1][n+1];
        memset(dp,0,sizeof dp);

        // LCS Code
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};
