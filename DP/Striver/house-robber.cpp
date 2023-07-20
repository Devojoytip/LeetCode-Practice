// https://leetcode.com/problems/house-robber

// TOP-DOWN
class Solution {
public:
    int f(vector<int>& v, int i, int n, vector<int> &dp) {
        
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];

        return dp[i]=max(v[i]+f(v,i+2,n,dp), f(v,i+1,n,dp));
    }
    int rob(vector<int>& v) {

        int n=v.size();
        vector<int> dp(n+1,-1);

        return f(v,0,n,dp);
    }
};

// BOTTOM-UP
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
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
        return recur(v, v.size());
    }
};
