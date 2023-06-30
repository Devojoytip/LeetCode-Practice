// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// check i-1 != j-1 when s[i-1]==s[j-1] to get 2 or more LCS
class Solution {
	public:
		int LongestRepeatingSubsequence(string s)
		{
		    // Code here
		    int n=s.size();
		    int dp[n+1][n+1];
		    memset(dp,0,sizeof dp);
		    
		    for(int i=1;i<=n;i++)
		    {
		        for(int j=1;j<=n;j++)
		        {
		            if(i-1!=j-1 and s[i-1]==s[j-1]) dp[i][j] = 1 + dp[i-1][j-1];  
		            else dp[i][j] = max( dp[i][j-1], dp[i-1][j]);
		        }
		    }
		    
		    return dp[n][n];
		}

};
