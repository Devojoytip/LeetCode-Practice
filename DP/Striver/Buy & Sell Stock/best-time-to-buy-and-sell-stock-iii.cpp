// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

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

    
    int TopDown(vector<int>& v, vector<vector<vector<int>>> &dp, int i, int buy, int cnt) 
    {

        if(i==v.size()) return 0;

        if(dp[i][buy][cnt] != -1) return dp[i][buy][cnt];

        int take = 0, notTake = 0;

        if(buy)
        {
            if(cnt>0) take = sol(v, dp, i+1, 0, cnt) - v[i];
            notTake = sol(v, dp, i+1, 1, cnt);
        }

        else
        {
            take = sol(v, dp, i+1, 1, cnt-1) + v[i];
            notTake = sol(v, dp, i+1, 0, cnt);
        }

        return dp[i][buy][cnt] = max(take, notTake);
    }  

    int solBottomUp(vector<int>&v){
        vector<vector<vector<int>>> dp(v.size()+1,vector<vector<int>>(2,vector<int>(3,0)));

        for(int i=v.size()-1;i>=0;i--)
        {
            for(int flag=0;flag<=1;flag++)
            {
                for(int cnt=1;cnt<=2;cnt++)
                {
                    if(flag) dp[i][flag][cnt] = max(dp[i+1][0][cnt]-v[i],dp[i+1][1][cnt]);
                    else dp[i][flag][cnt] = max(dp[i+1][1][cnt-1]+v[i],dp[i+1][0][cnt]);
                }
            }
        }
            
        return dp[0][1][2];
    }   

    int spaceOptimizedBottomUp(vector<int>&v){

        int n=v.size();
        vector<vector<int>> after(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));

        for(int i=n-1;i>=0;i--)
        {
            for(int flag=0;flag<=1;flag++)
            {
                for(int cnt=1;cnt<=2;cnt++)
                {
                    if(flag) curr[flag][cnt] = max(after[0][cnt]-v[i],after[1][cnt]);
                    else curr[flag][cnt] = max(after[1][cnt-1]+v[i],after[0][cnt]);
                }
            }
            after=curr;
        }
            
        return after[1][2];
    }   


    int maxProfit(vector<int>& v) {
        vector<vector<vector<int>>> dp(v.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
        // return sol(v,0,1,2,dp);
        // return solBottomUp(v);
        return spaceOptimizedBottomUp(v);
    }
};
