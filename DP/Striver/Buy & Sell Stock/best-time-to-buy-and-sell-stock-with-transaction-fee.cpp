// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

// Best Time to Buy and Sell Stock 2 var

class Solution {
public:

    int bottomUp(vector<int>&v, int fee){
        int n=v.size();
        int dp[n+1][2];
        dp[n][1]=dp[n][0]=0;// since nothing to buy or sell  
        
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<2;buy++)
            {
                if(buy) dp[i][buy]=max(-v[i]+dp[i+1][0],dp[i+1][1]);
                else dp[i][buy]=max(v[i]+dp[i+1][1]-fee,dp[i+1][0]);
            }
        }

        return dp[0][1];
    }

    int spaceOptimizedBottomUp(vector<int>&v, int fee){
        int n=v.size();
        int dp[n+1][2];
        vector<int> ahead(2,0),curr(2,0);// since nothing to buy or sell  
        
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<2;buy++)
            {
                if(buy) curr[buy]=max(-v[i]+ahead[0],ahead[1]);
                else curr[buy]=max(v[i]+ahead[1]-fee,ahead[0]);
            }
            ahead=curr;
        }

        return ahead[1];
    }

    int sol(vector<int>& v, vector<vector<int>> &dp, int i, int buy, int fee) 
    {
        if(i==v.size()) // return 0 simply or can check
        {
            if(buy) return 0;
            return -1e8;
        }

        if(dp[i][buy]!=-1) return dp[i][buy];

        int take=0, notTake=0;

        if(buy)
        {
            take = sol(v, dp, i+1, 0, fee) - v[i];
            notTake = sol(v, dp, i+1, 1, fee);
        }

        else
        {
            take = sol(v, dp, i+1, 1, fee) + v[i] - fee;
            notTake = sol(v, dp, i+1, 0, fee);
        }

        return dp[i][buy] = max(take, notTake);
    }

    int maxProfit(vector<int>& v, int fee) {
        // return recursive(v,0,1);
        vector<vector<int>> dp(v.size()+1,vector<int>(2,-1));
        return sol(v,dp,0,1,fee);
        // return bottomUp(v,fee);
        // return spaceOptimizedBottomUp(v,fee);
    }
};
