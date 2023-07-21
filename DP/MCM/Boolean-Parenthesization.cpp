// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// User function Template for C++

class Solution{
public:
    int f(int n, string s, int z, int i, int j, int dp[][201][2]){
        // code here
        
        if(i>j) return 0;
        
        if(i==j)
        {
            if(z and s[i]=='T') return dp[i][j][z]=1; 
            if(!z and s[i]=='F') return dp[i][j][z]=1;
            return 0; 
        }
        
        if(dp[i][j][z]!=-1) return dp[i][j][z];
        
        int ans=0;
        
        for(int k=i+1;k<j;k+=2)
        {
            int lt=f(n,s,1,i,k-1,dp);
            int lf=f(n,s,0,i,k-1,dp);
            int rt=f(n,s,1,k+1,j,dp);
            int rf=f(n,s,0,k+1,j,dp);
            
            char c=s[k];
            
            if(c=='^')
            {
                if(z) ans+=lt*rf + lf*rt;
                else ans+=lt*rt + lf*rf;
            }
            
            else if(c=='|')
            {
                if(z) ans+=lt*rf + lf*rt + lt*rt;
                else ans+= lf*rf;
            }
            
            else
            {
                if(z) ans+=lt*rt;
                else ans+=lt*rf + lf*rt + lf*rf;
            }
        }
        
        return dp[i][j][z]=ans%1003;
    }
    
    int countWays(int N, string S){
        // code here
        
        int dp[201][201][2];
        memset(dp,-1,sizeof dp);
        
        return f(N,S,1,0,N-1,dp);
    }
};
