// https://leetcode.com/problems/minimum-falling-path-sum-ii

class Solution {
public:
    int path(int i,int j,vector<vector<int>>& v,vector<vector<int>>& dp){
        
        if(i==v.size()-1) return v[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=INT_MAX;
        
        for(int k=0;k<v.size();k++){
            if(k==j) continue;
            
            ans=min(ans,v[i][j]+path(i+1,k,v,dp));
        }
        
        return dp[i][j]=ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& v) {
        int ans=INT_MAX;
        
        vector<vector<int>> dp(v.size(),vector<int> (v[0].size(),-1));
        
        for(int i=0;i<v.size();i++)
        {
            ans=min(ans,path(0,i,v,dp));
        }

        return ans;
    }
};
