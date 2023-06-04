// https://leetcode.com/problems/ones-and-zeroes

class Solution {
public:
    
    int sol(vector<string> &v, vector<vector<vector<int>>> &dp, int idx, int m, int n,int l) {
        
        if(idx==l) return 0;
        
        if(dp[idx][m][n]!=-1) return dp[idx][m][n];
        
        int ans=sol(v,dp,idx+1,m,n,l);
        
        string s=v[idx];
        int ones=count(s.begin(),s.end(),'1');
        int zeros=count(s.begin(),s.end(),'0');

        if(m>=zeros and n>=ones) ans=max(ans,1+sol(v,dp,idx+1,m-zeros,n-ones,l));

        return dp[idx][m][n]=ans;
    }
    int findMaxForm(vector<string>& v, int m, int n) {
        vector<vector<vector<int>>> dp(v.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return sol(v,dp,0,m,n,v.size());
    }
};
