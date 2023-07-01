// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution {
public:
    int dp[505][505];
    int palin[505][505];
    
    bool isPalindrome(string s,int i,int j)
    {
        if(palin[i][j]!=-1) return palin[i][j];
        
        s=s.substr(i,j-i+1);
        string a=s;
        reverse(s.begin(),s.end());
        
        return palin[i][j] = (a==s);
    }
    
    int sol(string s,int i,int j)
    {
        if(i==j)return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(isPalindrome(s,i,j)) return 0;
        
        int mini=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int left,right;
            
            if(dp[i][k]!=-1) left=dp[i][k];
            else left=sol(s,i,k);
            
            if(dp[k+1][j]!=-1) right=dp[k+1][j];
            else right=sol(s,k+1,j);
            
            int ans=left+right+1;
            
            mini=min(mini,ans);
        }
        
        return dp[i][j]=mini;
    }
    
    int palindromicPartition(string s) {
        
        memset(dp,-1,sizeof dp);
        memset(palin,-1,sizeof dp);
        
        return sol(s,0,s.length()-1);
    }
};
