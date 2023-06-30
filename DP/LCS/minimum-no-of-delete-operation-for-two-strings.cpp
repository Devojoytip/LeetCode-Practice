// https://leetcode.com/problems/delete-operation-for-two-strings
// Direct Code - n-lcs+m-lcs

class Solution {
public:
    int minDistance(string s1, string s2) {
        
        int n=s1.size(), m=s2.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof dp);

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int lcs=dp[n][m];

        return n-lcs+m-lcs;
    }
};
