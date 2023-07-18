// https://leetcode.com/problems/cherry-pickup

class Solution {
public:

    int dp[51][51][51];
    int dfs(int r1 , int c1 , int r2 , int n , vector<vector<int>> &v )
    {
        int c2=r1+c1-r2; // r1+c1 = r2+c2
        
        if(r1>=n or r2>=n or c1>=n or c2>=n or v[r1][c1]==-1 or v[r2][c2]==-1)
        {
            return INT_MIN;
        }
        
        if(dp[r1][c1][r2]!=-1)
        {
            return dp[r1][c1][r2];
        }
        
        if(r1==n-1 and c1==n-1)
        {
            // As r1+c1 = r2+c2 thus r1!=r2 and c1!=c2 to pick cherry as both are on same cell and so cherry can be picked only once
            return v[r1][c1]; 
        }
        
        int ans=v[r1][c1];
        
        if(r1!=r2 and c1!=c2)
        {
            ans += v[r2][c2];
        }
        
        ans += max({dfs(r1+1 , c1 , r2+1 , n , v) , dfs(r1 , c1+1 , r2 , n , v), dfs(r1+1 , c1 , r2 , n, v), dfs(r1 , c1+1 , r2+1 , n , v)});
        
        return dp[r1][c1][r2]=ans;
    }

    int cherryPickup(vector<vector<int>>& v) {
        
        memset(dp , -1 , sizeof(dp));
        int n=v.size();

        return max(0 , dfs(0,0,0,n,v));
    }
};
