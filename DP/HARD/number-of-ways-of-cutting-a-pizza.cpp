// https://www.youtube.com/watch?v=x05misqS7yI
// https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza

class Solution {
public:
    int ways(vector<string>& v, int k) {
        
        int n=v.size(), m=v[0].size();

        vector<vector<int>> pre(n+1, vector<int>(m+1,0));

        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                pre[i][j]=pre[i+1][j]+pre[i][j+1]-pre[i+1][j+1] + ((v[i][j]=='A') ? 1 : 0);
            }
        }

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k,-1)));
        
        return recur(pre,dp,0,0,k-1,n,m);
    }

    int recur(vector<vector<int>> &pre, vector<vector<vector<int>>> &dp, int r, int c, int k, int n, int m) {
        
        if(pre[r][c]==0) return 0;

        if(k==0) return 1;

        if(dp[r][c][k]!=-1) return dp[r][c][k];

        int ans=0;

        for(int i=r+1;i<n;i++)
        {
            if(pre[r][c]-pre[i][c]>0) ans= (ans + recur(pre,dp,i,c,k-1,n,m))%1000000007;
        }

        for(int i=c+1;i<m;i++)
        {
            if(pre[r][c]-pre[r][i]>0) ans= (ans + recur(pre,dp,r,i,k-1,n,m))%1000000007;
        }

        return dp[r][c][k]=ans%1000000007;
    }
};
