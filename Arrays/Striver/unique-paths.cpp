// https://leetcode.com/problems/unique-paths

class Solution {
public:
    int dp[101][101];

    int recur(int i,int j, int m, int n) 
    {
        if(i==m-1 and j==n-1) return 1;
    
        if(i>=m or j>=n) return 0;
    
        if(dp[i][j] != -1) return dp[i][j];
    
        return dp[i][j] = recur(i+1,j,m,n) + recur(i,j+1,m,n);
    }

    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof dp);
        return recur(0,0,m,n);
    }
};
