// https://leetcode.com/problems/dungeon-game

class Solution {
public:
int fun(int i,int j,vector<vector<int>>& v,vector<vector<int>> &dp){
    
    if(i>=v.size() or j>=v[0].size()) return 1e9;
    
    if(i==v.size()-1 and j==v[0].size()-1) 
    {
        if(v[i][j]<=0) return abs(v[i][j])+1;
        else return 1;
    } 
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int up=fun(i+1,j,v,dp);
    
    int down=fun(i,j+1,v,dp);
    
    // if cell has > 0 then he can get this much health from cell and no need to take it initially
    int minhealthreq=min(up,down) + (v[i][j]>=0 ? -v[i][j] : abs(v[i][j]));
    
    return dp[i][j]=(minhealthreq<=0)?1:minhealthreq;
}
    int calculateMinimumHP(vector<vector<int>>& v) {
        int m=v.size(),n=v[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
       return fun(0,0,v,dp); 
    }
};
