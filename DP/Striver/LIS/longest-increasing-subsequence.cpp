// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int sol(vector<int>& v, int idx, int prev, int n, vector<vector<int>> &dp)
    {
        if(idx==n) return 0;

        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];

        int take = 0, notTake = 0;

        if(prev==-1 or v[idx] > v[prev]) take = 1 + sol(v, idx+1, idx, n, dp);

        notTake = sol(v, idx+1, prev, n, dp);

        return dp[idx][prev+1] = max(take, notTake);

    }

    int solve(vector<int>& v)
    {
        int n=v.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i=0;i<n;i++) dp[i][0] = 1;
        
        int ans = 0;

        for(int idx=n-1;idx>=0;idx--)
        {
            for(int prev=idx-1;prev>=-1;prev--)
            {
                int take = 0, notTake = 0;

                if(prev==-1 or v[idx] > v[prev]) take = 1 + dp[idx+1][idx+1];

                notTake = dp[idx+1][prev+1];

                dp[idx][prev+1] = max(take, notTake);

                ans = max(ans, dp[idx][prev+1]);
            }
        }

        return ans;

    }

    int lengthOfLIS(vector<int>& v) {
        
        int n=v.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        // return sol(v,0,-1,n,dp);    
        return solve(v);    
    }
};
