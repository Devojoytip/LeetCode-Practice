// https://leetcode.com/problems/ugly-number-ii

class Solution {
public:
    int nthUglyNumber(int n) {

        vector<int> dp(n);
        dp[0]=1; // 1 is 1st ugly no
        int p1=0,p2=0,p3=0; // to keep track of curr nos in the tables of 2,3 and 5 and find the min

        for(int i=1;i<n;i++)
        {
            dp[i]=min({dp[p1]*2, dp[p2]*3, dp[p3]*5});

            if(dp[i]==dp[p1]*2) p1++;
          
            if(dp[i]==dp[p2]*3) p2++;
          
            if(dp[i]==dp[p3]*5) p3++;
        }

        return dp[n-1];
    }
};
