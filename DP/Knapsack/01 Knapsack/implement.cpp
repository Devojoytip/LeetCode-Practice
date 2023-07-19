// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int f(int w, int v[], int val[], int i, int n, vector<vector<int>> &dp) 
    { 
       // Your code here
       if(w==0 or i==n) return 0;
       
       if(dp[i][w]!=-1) return dp[i][w];
       
       if(v[i]<=w) dp[i][w] = max(f(w-v[i],v,val,i+1,n,dp)+val[i], f(w,v,val,i+1,n,dp));
       
       else dp[i][w] = f(w,v,val,i+1,n,dp);
       
       return dp[i][w];
       
    }
    
    int knapSack(int w, int v[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
       
       return f(w,v,val,0,n,dp);
    }
};

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       
       vector<vector<int>> dp(n+1,vector<int>(w+1,0));
       
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=w;j++)
           {
               if(wt[i-1]<=j) dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
                   
               else dp[i][j]=dp[i-1][j];
           }
       }
       
       return dp[n][w];
    }
};
