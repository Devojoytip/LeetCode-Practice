// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference

class Solution {
public:

    // TLE as its O(N^2)
    int LCS(vector<int>& v, int d, int i, int n) {
        
        int maxi=1;

        vector<int> dp(n+1,1);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(v[i]-v[j]==d) dp[i] = max(dp[j]+1, dp[i]);
            }
            maxi=max(maxi, dp[i]);
        }

        return maxi;
    }

    int sol(vector<int>& v, int d, int i, int n) {

        vector<int> dp(n,1);
        unordered_map<int, int> mp;
        int maxi=1;

        for(int i=0;i<n;i++)
        {
            int prev = v[i]-d;
            if(mp.find(prev)!=mp.end()) dp[i] = 1 + mp[prev];
            mp[v[i]] = dp[i];
            maxi=max(maxi, dp[i]);
        }

        return maxi;
    }

    int longestSubsequence(vector<int>& v, int d) {
        
        int n=v.size();
        return sol(v,d,0,n);
    }
};
