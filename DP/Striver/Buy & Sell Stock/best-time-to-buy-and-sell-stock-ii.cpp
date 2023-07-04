// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

// All 4 ways

class Solution {
public:

    /*
    1. Recurvise 

    int sol(vector<int>& v,int i,int curr) {
        if(i==v.size()) return 0;
        int profit=INT_MIN;

        // curr==-1 means it is not holding any stock
        if(curr==-1) profit=max(sol(v,i+1,v[i]),sol(v,i+1,-1));
        else profit=max(sol(v,i+1,-1)+v[i]-curr,sol(v,i+1,curr));
        return profit;
    }

    */

    int recursive(vector<int>& v,int i,int buy) {
        if(i==v.size()) return 0;
        int profit=INT_MIN;

        if(buy) profit=max(-v[i]+recursive(v,i+1,0),recursive(v,i+1,buy));
        else profit=max(recursive(v,i+1,1)+v[i],recursive(v,i+1,buy));
        
        return profit;
    }

    int memoized(vector<int>&v,int i,int buy,vector<vector<int>>&dp){
        
        if(i==v.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit=0,take,not_take;
        
        if(buy)
        {
            take=memoized(v,i+1,0,dp)-v[i];
            not_take=memoized(v,i+1,1,dp);
        }
        
        else
        {
            take=memoized(v,i+1,1,dp)+v[i];
            not_take=memoized(v,i+1,0,dp);
        }
        
        return dp[i][buy]=max(take,not_take);
    }

    int bottomUp(vector<int>&v){
        int n=v.size();
        int dp[n+1][2];
        dp[n][1]=dp[n][0]=0;// since nothing to buy or sell  
        
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<2;buy++)
            {
                if(buy) dp[i][buy]=max(-v[i]+dp[i+1][0],dp[i+1][1]);
                else dp[i][buy]=max(v[i]+dp[i+1][1],dp[i+1][0]);
            }
        }

        return dp[0][1];
    }

    int spaceOptimizedBottomUp(vector<int>&v){
        int n=v.size();
        int dp[n+1][2];
        vector<int> ahead(2,0),curr(2,0);// since nothing to buy or sell  
        
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<2;buy++)
            {
                if(buy) curr[buy]=max(-v[i]+ahead[0],ahead[1]);
                else curr[buy]=max(v[i]+ahead[1],ahead[0]);
            }
            ahead=curr;
        }

        return ahead[1];
    }


    int maxProfit(vector<int>& v) {
        vector<vector<int>> dp(v.size()+1,vector<int>(2,-1));
        // return recursive(v,0,1);
        // return memoized(v,0,1,dp);
        // return bottomUp(v);
        return spaceOptimizedBottomUp(v);
    }
};
