// https://leetcode.com/problems/minimum-falling-path-sum 

class Solution {
public:

    int recur(vector<vector<int>>& v, int i,int j, int m, int n) 
    {
        int dp[101][101];
        memset(dp,-1,sizeof dp);
        int ans=1e9;
    
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0) dp[i][j] = v[i][j];

                else
                {
                    int above = dp[i-1][j];

                    int diag1 = (j==0) ? 1e9 : dp[i-1][j-1];
                    
                    int diag2 = (j==n-1) ? 1e9 : dp[i-1][j+1];

                    dp[i][j] = v[i][j] + min({above, diag1, diag2});
                }

                if(i==m-1) ans = min(ans, dp[i][j]);
            }
        }
    
        return ans;
    }

    int minFallingPathSum(vector<vector<int>>& v) {
        return recur(v,0,0,v.size(),v.size());
    }
};
