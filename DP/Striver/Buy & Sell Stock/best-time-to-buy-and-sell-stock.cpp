// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& v) {
        
        int mini=1e8, ans=-1e8;

        for(auto it: v)
        {
            mini = min(mini, it);
            ans= max(ans, it-mini);
        }

        return ans;
    }
};
