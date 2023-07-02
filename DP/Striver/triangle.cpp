// https://leetcode.com/problems/triangle

class Solution {
public:

    int minimumTotal(vector<vector<int>>& v) 
    {
        vector<vector<int>> dp(205,vector<int>(205,1e9));
        int ans=INT_MAX;

        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                if(i==0) dp[i][j]=v[i][j];
                
                else 
                {
                    int prev1 = dp[i-1][j];
                    int prev2 = (j==0) ? 1e9 : dp[i-1][j-1];
                    
                    dp[i][j] = v[i][j] + min(prev1, prev2);
                }

                if(i==v.size()-1) ans = min(ans, dp[i][j]);
            }
        }

        return ans;
    }
};
