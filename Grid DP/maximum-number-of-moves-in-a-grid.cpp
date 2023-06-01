/*

https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/

*/

class Solution {
public:
    int recur(vector<vector<int>>& v,vector<vector<int>> &dp,int i,int j,int val)
    {
        if(i<0 or j>=v[0].size() or i>=v.size() or v[i][j]<=val) return -1;

        if(j==v[0].size()-1) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j] = max({recur(v,dp,i-1,j+1,v[i][j])+1, recur(v,dp,i,j+1,v[i][j])+1, recur(v,dp,i+1,j+1,v[i][j])+1});
    }
    
    int maxMoves(vector<vector<int>>& v) 
    {

        int m=v.size(),n=v[0].size(),ans=0;

        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));

        for(int i=0;i<m;i++) ans=max(ans,recur(v,dp,i,0,-1));

        return ans;
    }
};
