// https://leetcode.com/problems/maximal-square

class Solution {
public:
    int maximalSquare(vector<vector<char>>& v) {
      
        int m=v.size(),n=v[0].size(),ans=-1;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
      
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(v[i-1][j-1]=='1') dp[i][j]=min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]})+1;
                ans=max(ans,dp[i][j]);
            }
        }
      
        return ans*ans;
    }
};
