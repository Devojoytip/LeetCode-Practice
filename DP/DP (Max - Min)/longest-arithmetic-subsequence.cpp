// https://leetcode.com/problems/longest-arithmetic-subsequence

class Solution {
public:
    int longestArithSeqLength(vector<int>& v) {

        int n=v.size(),ans=0;
        vector<vector<int>> dp(n+1,vector<int>(1001,1));

        // 1st type loop
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=v[i]-v[j];
                dp[i][diff+500]=max(dp[i][diff+500], 1+dp[j][diff+500]);
                ans=max(ans,dp[i][500+diff]);
            }
        }

        // 2nd type loop
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int diff=v[j]-v[i];
                int idx=diff+500;

                if(dp[j][idx]<1+dp[i][idx]) dp[j][idx]=1+dp[i][idx];
                ans=max(ans, dp[j][idx]);
            }
        }

        return ans;
    }
};
