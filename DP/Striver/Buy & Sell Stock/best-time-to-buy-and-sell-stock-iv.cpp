// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:

    // TOP-DOWN
    int sol(vector<int>& v, vector<vector<vector<int>>> &dp, int i, int buy, int cnt) 
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

    // BOTTOM-UP
    int spaceOptimizedBottomUp(int k,vector<int>&v){
        int n=v.size();

        vector<vector<int>> after(2,vector<int>(k+1,0));
        vector<vector<int>> curr(2,vector<int>(k+1,0));

        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cnt=1;cnt<=k;cnt++)
                {
                    if(buy) curr[buy][cnt]=max(-v[i]+after[0][cnt],after[1][cnt]);
                    else curr[buy][cnt]=max(v[i]+after[1][cnt-1],after[buy][cnt]);
                }
            }
            after=curr;
        }

        return after[1][k];
    } 

    int maxProfit(int k, vector<int>& v) {

        vector<vector<vector<int>>> dp(v.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return sol(v, dp, 0, 1, k);

        // return spaceOptimizedBottomUp(k,v);
    }
};
