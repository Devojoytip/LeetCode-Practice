// https://leetcode.com/problems/2-keys-keyboard

class Solution {
public:
    int sol(vector<vector<int>> &dp, int curr, int clip, int n) {
        if(n<curr or n<clip) return 1e8;

        if(n==1 or curr==n) return 0;

        if(dp[curr][clip]!=-1) return dp[curr][clip];

        int copy=1e8, paste=1e8;

        if(curr!=clip) copy=1+sol(dp,curr,curr,n); // else it leads to infinite copying of same word again and again

        if(clip!=0) paste=1+sol(dp,curr+clip,clip,n); // else it pastes 0 text infinitely

        return dp[curr][clip]=min(copy,paste);

    }
    int minSteps(int n) {
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return sol(dp,1,0,n);
    }
};
