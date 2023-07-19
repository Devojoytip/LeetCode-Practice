// https://leetcode.com/problems/partition-equal-subset-sum

// BU
class Solution {
public:
    bool f(vector<int>& v, int i, int t, vector<vector<int>> &dp)
    {
        if(i==v.size() and t==0) return 1;

        if(i>=v.size()) return 0;

        if(dp[i][t]!=-1) return dp[i][t];

        if(v[i]<=t) dp[i][t]=f(v,i+1,t,dp) or f(v,i+1,t-v[i],dp);
        
        else dp[i][t]=f(v,i+1,t,dp);

        return dp[i][t];
    }

    bool canPartition(vector<int>& v) {
        
        int sum=0;

        for(auto it: v) sum+=it;

        if(sum%2) return 0;

        sum/=2;
        
        vector<vector<int>> dp(v.size()+1, vector<int>(sum+1,-1));

        return f(v,0,sum,dp);
    }
};

// TD
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
