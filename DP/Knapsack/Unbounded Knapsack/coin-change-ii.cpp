// https://leetcode.com/problems/coin-change-ii

// Count no of subsets with given sum 

// TD
class Solution {
public:
int f(int i, int n, int w, vector<int>& v, vector<vector<int>> &dp)
    {
        // code here
        if(w==0) return 1;

        if(i>=n) return 0;
        
        if(dp[i][w]!=-1) return dp[i][w];
        
        if(w>=v[i]) dp[i][w] = f(i,n,w-v[i],v,dp) + f(i+1,n,w,v,dp);
        
        else dp[i][w] = f(i+1,n,w,v,dp);
        
        return dp[i][w];
    }
    
    int change(int t, vector<int>& v) {
        int n=v.size();
        vector<vector<int>> dp(n+1,vector<int>(t+1,-1));

        return f(0,n,t,v,dp);
    }
};

class Solution {
public:
int change(int sum, vector<int>& v) {
	int n = v.size();
	vector<vector<int>> dp(n+1,vector<int>(sum+1,0));

	for (int i = 0; i <= n; i++) dp[i][0] = 1; // Don't include any coin thus 1 way

	for (int i = 1; i <= n; i++) 
  {
    for (int j = 1; j <= sum; j++) 
    {
        if (v[i - 1] <= j) dp[i][j] = dp[i][j - v[i - 1]] + dp[i - 1][j];
        else dp[i][j] = dp[i - 1][j];
    }
}
	return dp[n][sum];
}
};
