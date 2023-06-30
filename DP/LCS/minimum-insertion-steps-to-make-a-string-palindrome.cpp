// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome

// s.size() - LPS -> For both, min no of insertions and min no of deletions

class Solution {
public:
    int dp[501][501];

    int LPS(string a,string b,int n) {
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

    int minInsertions(string s) {
        memset(dp,0,sizeof dp);
        string a=s;
        reverse(s.begin(),s.end());
        string b=s;

        return s.size() -LPS(a,b,s.size());
    }
};
