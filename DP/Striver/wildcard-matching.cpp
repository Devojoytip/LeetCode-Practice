// https://leetcode.com/problems/wildcard-matching

class Solution {
public:

    // MY APPROACH - TOP-DOWN
    bool sol(vector<vector<int>> &dp, string s, string p, int i, int j, int n, int m) 
    {
        if(i==n and j==m) return 1;        

        if(i<n and j==m) 
        {
            if(m==0) return 0;
            if(p[j-1]=='*') return 1;
            return 0;
        }

        if(i==n and j<m) 
        {
            while(j<m and p[j]=='*') j++;
            return (j==m) ? 1 : 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==p[j]) return dp[i][j] = sol(dp,s,p,i+1,j+1,n,m);

        if(s[i]!=p[j] and p[j] >= 'a' and  p[j] <= 'z') return dp[i][j] = 0;

        if(p[j]=='?') return dp[i][j] = sol(dp,s,p,i+1,j+1,n,m);

        while(j+1<m and p[j+1]=='*') j++;

        // int takeBoth = sol(dp,s,p,i+1,j+1,n,m);
        
        // int takeLetter = sol(dp,s,p,i+1,j,n,m);

        // int takeStar = sol(dp,s,p,i,j+1,n,m);

        bool res = sol(dp,s,p,i+1,j+1,n,m) or sol(dp,s,p,i+1,j,n,m) or sol(dp,s,p,i,j+1,n,m);

        return dp[i][j] = res;
    }

    bool isMatch(string s, string p) {
        
        int n=s.size(), m=p.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return sol(dp,s,p,0,0,n,m);
    }
};
