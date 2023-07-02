// https://leetcode.com/problems/house-robber

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
