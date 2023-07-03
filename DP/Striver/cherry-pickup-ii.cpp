// https://leetcode.com/problems/cherry-pickup-ii

class Solution {
public:
    int recur(vector<vector<int>>& v, vector<vector<vector<int>>>& dp, int i,int j1,int j2, int m,int n) {
        
        if(j1<0 or j2<0 or j1>=n or j2>=n) return -1e8;

        if(i==m-1)
        {
            if(j1==j2) return v[i][j1];

            return v[i][j1] + v[i][j2];
        }

        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2] ;

        for(int dj1=-1;dj1<=1;dj1++)
        {
            for(int dj2=-1;dj2<=1;dj2++)
            {
                int cherries= (j1==j2) ? v[i][j1] : v[i][j1] + v[i][j2];

                dp[i][j1][j2] = max(dp[i][j1][j2], recur(v,dp,i+1,j1+dj1,j2+dj2,m,n) + cherries);
            }
        }

        return dp[i][j1][j2];
    }

    int cherryPickup(vector<vector<int>>& v) {

        int m=v.size(), n=v[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n, vector<int>(n,-1)));

        return recur(v,dp,0,0,n-1,m,n); 
    }
};
