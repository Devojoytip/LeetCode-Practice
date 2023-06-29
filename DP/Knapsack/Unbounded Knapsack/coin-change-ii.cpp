// https://leetcode.com/problems/coin-change-ii

// Count no of subsets with given sum 

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
