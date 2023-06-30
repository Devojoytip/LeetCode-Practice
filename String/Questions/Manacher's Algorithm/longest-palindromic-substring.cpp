// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:

    string lcs(int x, int y, string s, string t)
    {
        vector<vector<int>> dp(x+1, vector<int>(y+1,0));
        if(x==0 or y==0) return 0;
        
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
                if(s[i-1]==t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0;
            }
        }

        string res="";
        int i=x,j=y;

        while(i>0 and j>0)
        {
            if(s[i-1]==t[j-1])
            {
                res.push_back(s[i-1]);
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1]) i--;
                else j--;
            }
        }
        
        reverse(res.begin(),res.end());
        return res;
    }

    string longestPalindrome(string s) {
        int n=s.size();
        string t=s;
        reverse(s.begin(),s.end());
        return lcs(n,n,s,t);
    }
};
