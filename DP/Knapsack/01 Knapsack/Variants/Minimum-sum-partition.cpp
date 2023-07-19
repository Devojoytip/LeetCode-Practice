// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{

  public:
  
	int f(int a[], int i, int n, int s, int t, vector<vector<int>> &dp)  { 
	    // Your code goes here
	    
	    if(i==n and s<=t) return s;
	    
	    if(s>t or i>=n) return -1;
	    
	    if(dp[i][s]!=-1) return dp[i][s];
	    
	    if(s+a[i]<=t) dp[i][s]=max(f(a,i+1,n,s+a[i],t,dp), f(a,i+1,n,s,t,dp));
	    
	    else dp[i][s]=f(a,i+1,n,s,t,dp);
	    
	    return dp[i][s];
	} 
	
	int minDifference(int a[], int n)  { 
	    // Your code goes here
	    
	    int sum=0;
	    for(int i=0;i<n;i++) sum+=a[i];
	    int t=sum/2;
	    
	    vector<vector<int>> dp(n+1, vector<int>(t+1,-1));
	    
	    return sum-2*f(a,0,n,0,t,dp);
	} 
};

class Solution{

  public:
	int sol(int a[], int sum, int n)  { 
	    // Your code goes here
	    
	    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=sum;j++)
	        {
	            if(a[i-1]<=j) dp[i][j]=max(a[i-1]+dp[i-1][j-a[i-1]],dp[i-1][j]);
	            else dp[i][j]=dp[i-1][j];
	        }
	    }
	    
	    return dp[n][sum];
	} 
	
	int minDifference(int a[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++) sum+=a[i];
	    int minSet=sol(a,sum/2,n);
	    
	    return sum-2*minSet;
	} 
};
