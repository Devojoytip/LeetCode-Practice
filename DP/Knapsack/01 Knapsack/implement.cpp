// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1001][1001];
    
    int sol(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       if(!n or !w)return 0;
       
       if(dp[n][w]!=-1) return dp[n][w];
       
       if(wt[n-1]<=w) return dp[n][w]=max(val[n-1]+sol(w-wt[n-1],wt,val,n-1),sol(w,wt,val,n-1));
       
       return dp[n][w]=sol(w,wt,val,n-1);
    }
    
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(dp,-1,sizeof(dp));
       return sol(w,wt,val,n);
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
