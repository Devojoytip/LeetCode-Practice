// https://leetcode.com/problems/longest-arithmetic-subsequence

class Solution {
public:
    int longestArithSeqLength(vector<int>& v) {

        int n=v.size(),ans=0;
        vector<vector<int>> dp(n+1,vector<int>(1001,1));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=v[i]-v[j];
                dp[i][diff+500]=max(dp[i][diff+500], 1+dp[j][diff+500]);
                ans=max(ans,dp[i][500+diff]);
            }
        }

        return ans;
    }
};
