// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

// Version of Best Time to Buy and Sell Stock 2
class Solution {
public:

    // BOTTOM-UP
    int sol(vector<int>& v, vector<vector<int>> &dp, int i, int buy) 
    {
        if(i>=v.size()) 
        {
            if(buy) return 0;
            return -1e8;
        }

        if(dp[i][buy]!=-1) return dp[i][buy];

        int take=0, notTake=0;

        if(buy)
        {
            take = sol(v, dp, i+1, 0) - v[i];
            notTake = sol(v, dp, i+1, 1);
        }

        else
        {
            take = sol(v, dp, i+2, 1) + v[i];
            notTake = sol(v, dp, i+1, 0);
        }

        return dp[i][buy] = max(take, notTake);
    }

    int spaceOptimizedBottomUp(vector<int>&v){
        int n=v.size();

        vector<int> curr(2,0);
        vector<int> ahead1(2,0);
        vector<int> ahead2(2,0);

        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy) curr[buy]=max(-v[i]+ahead1[0],ahead1[1]);
                else curr[buy]=max(v[i]+ahead2[1],ahead1[buy]);
            }
            ahead2=ahead1;
            ahead1=curr;
        }

        return ahead1[1];
    }

    int maxProfit(vector<int>& v) {
        // return BottomUp(v);
        return spaceOptimizedBottomUp(v);
    }
};
