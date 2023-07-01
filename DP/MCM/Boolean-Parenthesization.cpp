// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// User function Template for C++

class Solution{
public:
    int dp[305][305][5];
    int sol(string s,int i,int j,bool inp)
    {
        if(i>j)return 0;
        int z=0;
        if(inp) z=1;
        
        if(i==j)
        {
            if(inp and s[i]=='T') return dp[i][j][z]=1; 
            if(!inp and s[i]=='F') return dp[i][j][z]=1;
            return 0; 
        }
        
        if(dp[i][j][z]!=-1) return dp[i][j][z];
        int ans=0;
        for(int k=i+1;k<j;k+=2)
        {
            int lt=sol(s,i,k-1,1);
            int lf=sol(s,i,k-1,0);
            int rt=sol(s,k+1,j,1);
            int rf=sol(s,k+1,j,0);
            if(s[k]=='|') 
            {
                if(inp) ans+=lf*rt+lt*rt+lt*rf;
                else ans+=lf*rf;
            }
            else if(s[k]=='&') 
            {
                if(inp) ans+=lt*rt;
                else ans+=lf*rt+lf*rf+lt*rf;
            }
            else
            {
                if(inp) ans+=lt*rf+lf*rt;
                else ans+=lt*rt+lf*rf;
            }
        }
        
        return dp[i][j][z]=ans%1003;
    }
    int countWays(int n, string s){
        // code here
        memset(dp,-1,sizeof dp);
        return sol(s,0,s.length()-1,1);
    }
};
