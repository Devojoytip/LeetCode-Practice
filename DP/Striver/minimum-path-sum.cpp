// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& v) 
    {
        int m=v.size();
        int n=v[0].size();
    
        int dp[500][500];
        memset(dp,0,sizeof dp);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 and j==0) dp[i][j] = v[i][j];

                else
                {
                    int left = (i==0) ? INT_MAX : dp[i-1][j];

                    int up = (j==0) ? INT_MAX : dp[i][j-1];

                    dp[i][j] = v[i][j] + min(left, up);
                }
            }
        }

        return dp[m-1][n-1];
    }
};
