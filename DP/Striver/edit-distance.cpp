// https://leetcode.com/problems/edit-distance

class Solution {
public:
    int sol(vector<vector<int>> &dp, string a, string b, int i, int j, int n, int m) 
    {
        if(i==n and j==m) return dp[i][j] = 0;

        if(i==n and j<m) return dp[i][j] = m-j; // insert rem ele of b to a        
        
        if(i<n and j==m) return dp[i][j] = n-i;  // delete rem ele of a to convert to b 

        if(dp[i][j]!=-1) return dp[i][j];

        if(a[i]==b[j]) return dp[i][j] = sol(dp,a,b,i+1,j+1,n,m);

        else 
        {
            int insertCost = sol(dp,a,b,i,j+1,n,m);

            int deleteCost = sol(dp,a,b,i+1,j,n,m);
            
            int replaceCost = sol(dp,a,b,i+1,j+1,n,m);

            return dp[i][j] = 1 + min({insertCost, deleteCost, replaceCost});
        }        
    }
    int minDistance(string a, string b) {
        
        int n=a.length();
        int m=b.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return sol(dp,a,b,0,0,n,m);
    }
};
