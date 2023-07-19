// https://leetcode.com/problems/target-sum

// BOTTOM-UP
class Solution {
public:
    int recur(vector<int>& v, int i, int n, int t, vector<vector<int>> &dp) {

        if(t==0 and i==n) return 1;

        if(i>=n) return 0;

        if(dp[i][t]!=-1) return dp[i][t];

        if(v[i]<=t) dp[i][t]=recur(v,i+1,n,t-v[i],dp)+recur(v,i+1,n,t,dp);
        
        else dp[i][t]=recur(v,i+1,n,t,dp);

        return dp[i][t];
    }

    int findTargetSumWays(vector<int>& v, int target) {

        int n=v.size(), sum=0;

        for(auto it: v) sum+=it;

        int t=sum+target;

        if(t%2 or t<0) return 0;

        t/=2;

        vector<vector<int>> dp(n+1, vector<int>(t+1,-1));

        return recur(v,0,n,t,dp);
    }
};

// TOP-DOWN
class Solution {
    int solve(vector<int>& arr, int n, int sum,vector<vector<int>> &dp){
        for(int i=0;i<=n;i++) dp[i][0]=1;
        
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=sum; j++) // start from 0 as sum can be 0
            {
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
