// Subset Sum Problem
// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{   
public:
    bool f(vector<int>v, int i, int n, int s, vector<vector<int>> &dp){
        // code here 
        if(s==0) return 1;
        
        if(i==n) return 0;
        
        if(dp[i][s]!=-1) return dp[i][s];
        
        if(v[i]<=s) dp[i][s]= f(v,i+1,n,s,dp) or f(v,i+1,n,s-v[i],dp);
        
        else dp[i][s]= f(v,i+1,n,s,dp);
        
        return dp[i][s];
    }
    
    bool isSubsetSum(vector<int>v, int sum){
        // code here 
        int n=v.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1,-1));
        return f(v,0,n,sum,dp);
    }
};

class Solution{   
public:
    bool isSubsetSum(vector<int>v, int sum){
        // code here 
        int n=v.size();
        
        vector<vector<bool>> dp(n+1,vector<bool> (sum+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(v[i-1]<=j) dp[i][j]= dp[i-1][j] or dp[i-1][j-v[i-1]];
                else dp[i][j]= dp[i-1][j];
            }
        }
        
        return dp[n][sum];
    }
};
