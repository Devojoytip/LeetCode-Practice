// https://leetcode.com/problems/burst-balloons

class Solution {
public:
    int dp[305][305];
    int sol(vector<int>& v,int i,int j,int n)
    {
        if(i>j)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int maxi=-1;
        
        int a=(i-1<0)?1:v[i-1];
        int b=(j+1>=n)?1:v[j+1];
        
        for(int k=i;k<=j;k++)
        {
            int ans=sol(v,i,k-1,n)+sol(v,k+1,j,n)+a*v[k]*b;
            maxi=max(maxi,ans);
        }
        return dp[i][j]=maxi;
    }
    
    int maxCoins(vector<int>& v) {
        memset(dp,-1,sizeof dp);
        return sol(v,0,v.size()-1,v.size());
    }
};
