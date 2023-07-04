// https://leetcode.com/problems/longest-string-chain

class Solution {
public:
    bool check(string a, string b)
    {
        int i=0, j=0, n=a.size(), m=b.size();

        if(n-m != 1) return 0;

        while(i<n)
        {
            if(j < m and a[i]==b[j]) i++, j++;
            else i++;
        }

        return i==n and j==m;
    }

    static bool cmp (const string &a, const string &b)
    {
        return a.size() < b.size();
    }

    // TOP-DOWN
    int sol(vector<string>& v, vector<int> &dp, string s, int i) 
    {
        if(i==0) return dp[i]=1;

        if(dp[i] != 1) return dp[i];

        for(int j=0;j<i;j++)
        {
            if(check(s,v[j]) and 1 + dp[j] > dp[i]) dp[i] = 1 + dp[j];
        }

        return dp[i];
    }

    // BOTTOM-UP

    int solve(vector<string> &v)
    {
        sort(v.begin(), v.end(),cmp);
        int n = v.size(), ans = 0;
        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (check(v[i], v[prev]) and dp[i] < 1 + dp[prev]) dp[i] = 1 + dp[prev];
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }

    int longestStrChain(vector<string>& v) {
        
        sort(v.begin(), v.end(), cmp);
        
        int n=v.size();
        vector<int> dp(n,1);
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            ans=max(ans, sol(v, dp, v[i], i));
        }

        return ans;
    }
};
