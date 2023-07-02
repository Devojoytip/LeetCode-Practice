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

// TABULATION / BOTTOM-UP

class Solution {
public:

    int recur(int i,int j, int m, int n) 
    {
        int dp[101][101];
        memset(dp,-1,sizeof dp);
    
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 and j==0) dp[i][j] = 1;

                else
                {
                    int left = (i==0) ? 0 : dp[i-1][j];

                    int up = (j==0) ? 0 : dp[i][j-1];

                    dp[i][j] = left + up;
                }
            }
        }
    
        return dp[m-1][n-1];
    }

    int uniquePaths(int m, int n) {
        
        return recur(0,0,m,n);
    }
};
