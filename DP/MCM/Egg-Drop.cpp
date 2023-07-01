// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution {
public:
    
    int MCM(int e, int f,vector<vector<int>> &dp) {
        
        if(f==1 or f==0) return f;

        if(e==1) return f;

        if(dp[e][f]!=-1) return dp[e][f];

        int ans=1e8;
        
        for(int k=1;k<=f;k++)
        {
            int Break=MCM(e-1,k-1,dp);
            int notBreak=MCM(e,f-k,dp);
            int temp= 1 + max(Break,notBreak);
            ans=min(ans,temp);
        }

        return dp[e][f]=ans;
    }
    
    int twoEggDrop(int e, int f) {

        vector<vector<int>> dp(e+1,vector<int> (f+1,-1));
        return MCM(e,f,dp);
    }
};
