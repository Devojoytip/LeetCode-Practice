// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int recur(int a[], int dp[], int idx, int n)
    {
        // Your code here
        if(idx>=n) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        int take = recur(a,dp,idx+2,n) + a[idx];
        
        int notTake = recur(a,dp,idx+1,n);
        
        return dp[idx] = max(take, notTake);
        
    }
    
    int FindMaxSum(int a[], int n)
    {
        // Your code here
        int dp[n+1];
        memset(dp,-1,sizeof dp);
        
        return recur(a,dp,0,n);
        
    }
};

// BOTTOM-UP

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int recur(int a[], int n)
    {
        // Your code here
        int dp[n+1];
        
        memset(dp,-1,sizeof dp);
        
        for(int i=0;i<n;i++)
        {
            int take = (i>=2) ? dp[i-2] + a[i] : a[i];
            
            int notTake = (i>=1) ? dp[i-1] : 0;
            
            dp[i] = max(take, notTake);
        }
        
        return dp[n-1];
        
    }
    
    int FindMaxSum(int a[], int n)
    {
        // Your code here
        
        return recur(a,n);
        
    }
};
