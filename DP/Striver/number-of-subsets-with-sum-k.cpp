// https://www.codingninjas.com/studio/problems/number-of-subsets_3952532?leftPanelTab=0

const int MOD = 1000000007;

// TOP-DOWN
int sol(vector<int>& v, vector<vector<long long int>>& dp, int k, int idx, int curr, int n)
{
	// Write your code here.
	if(curr==k) return 1;

	if(idx>=n and curr!=k) return 0;

	if(curr>k) return 0;

	if(dp[idx][curr]!=-1) return dp[idx][curr];

	long long int take = sol(v,dp,k,idx+1,curr+v[idx],n);

	long long int NotTake = sol(v,dp,k,idx+1,curr,n);

	return dp[idx][curr] = (take%MOD + NotTake%MOD) %MOD;
}

// TOP-DOWN
int BottomUp(vector<int>& v, int k, int n)
{
	// Write your code here.
	vector<vector<long long int>> dp(v.size(),vector<long long int>(1002,0));
		
	for(int i=0;i<n;i++) dp[i][0] = 1;
	
	if(v[0]<=k) dp[0][v[0]] = 1;
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			long long int take = (v[i]<=j) ? dp[i-1][j-v[i]] : 0;

			long long int NotTake = dp[i-1][j];
		
			dp[i][j] = (take%MOD + NotTake%MOD) %MOD;
		}
	}

	return dp[n-1][k]%MOD;
}

int findWays(vector<int>& v, int k)
{
	// Write your code here.
	vector<vector<long long int>> dp(v.size(),vector<long long int>(1002,-1));
	return sol(v,dp,k,0,0,v.size())%MOD;
}
