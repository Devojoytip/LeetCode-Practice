// https://leetcode.com/problems/combination-sum-iv

class Solution {
public:
    int recur(vector<int>& v, int idx, int sum, vector<vector<int>> &dp) {
        
        if(sum==0) return 1;

        if(idx==v.size()) return 0;

        if(dp[idx][sum]!=-1) return dp[idx][sum];

        int ans=0;

        for(int i=idx;i<v.size();i++)
        {
            if(v[i]>sum) continue;

            ans += recur(v,idx,sum-v[i],dp);
        }

        return dp[idx][sum] = ans;
    }

    int combinationSum4(vector<int>& v, int sum) {
        
        vector<vector<int>> dp(v.size(), vector<int>(sum+1,-1));

        return recur(v,0,sum,dp);
    }
};
