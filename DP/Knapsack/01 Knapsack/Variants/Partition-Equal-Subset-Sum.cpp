// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    
    bool sol(vector<int>& arr,int n,int sum,vector<vector<bool>> dp)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j>=arr[i-1]) dp[i][j]=dp[i-1][j-arr[i-1]] or dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }

    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(auto it:arr) sum+=it;
        if(sum%2) return 0;
        sum/=2;
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,0));
        dp[0][0]=1;
        return sol(arr,n,sum,dp);
    }
};
