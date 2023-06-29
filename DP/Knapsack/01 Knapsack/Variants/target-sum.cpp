// https://leetcode.com/problems/target-sum

class Solution {
    int solve(vector<int>& arr, int n, int sum,vector<vector<int>> &dp){
        for(int i=0;i<=n;i++) dp[i][0]=1;
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<=sum; j++){
                if(arr[i-1]<=j) dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
public:
    int findTargetSumWays(vector<int>& arr, int t) {
        int s=0;
        for(auto it:arr) s+=it;
        // (t+s)=2*S1 from the equation, where S1 is subset with larger sum thus (t+s)%2==0
        // also t>s not possible 
        if((t+s)%2)return 0;
        int sum=(s+t)/2;
        if(sum<0)return 0;
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        return solve(arr, n, sum, dp);
    }
};
