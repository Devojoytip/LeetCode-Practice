// https://leetcode.com/problems/house-robber-ii

class Solution
{
    public:
    //DIFF:
    // Only 1st & last house will be affected as they become adjacent
    
    int f(vector<int>& v, int i, int n, vector<int> &dp) {
        
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];

        return dp[i]=max(v[i]+f(v,i+2,n,dp), f(v,i+1,n,dp));
    }
    
    int rob(vector<int> &v) 
    {
        int n = v.size();

        if(n==1) return v[0];

        vector<int> u1; // to calc ans excluding last ele
        vector<int> u2; // to calc ans excluding 1st ele

        for(int i=0;i<n;i++)
        {
            if(i!=n-1) u1.push_back(v[i]);
            if(i!=0) u2.push_back(v[i]);
        }
        
        vector<int> dp1(n-1,-1);
        vector<int> dp2(n-1,-1);

        return max(f(u1, 0, n-1, dp1), f(u2, 0, n-1, dp2));
    }
};


class Solution
{
    public:
    //DIFF:
    // Only 1st & last house will be affected as they become adjacent
    int recur(vector<int> &v, int n)
    {
        // Your code here
        int dp[n+1];
        
        memset(dp,-1,sizeof dp);
        
        for(int i=0;i<n;i++)
        {
            int take = (i>=2) ? dp[i-2] + v[i] : v[i];
            
            int notTake = (i>=1) ? dp[i-1] : 0;
            
            dp[i] = max(take, notTake);
        }
        
        return dp[n-1];
        
    }
    
    int rob(vector<int> &v) 
    {
        int n = v.size();

        if(n==1) return v[0];

        vector<int> u1; // to calc ans excluding last ele
        vector<int> u2; // to calc ans excluding 1st ele

        for(int i=0;i<n;i++)
        {
            if(i!=n-1) u1.push_back(v[i]);
            if(i!=0) u2.push_back(v[i]);
        }

        return max(recur(u1, n-1), recur(u2, n-1));
    }
};
