// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

/*

Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

*/

// LCS Pattern 

class Solution {
public:
    int dp[1001][1001];

    int sol(vector<int>& a, vector<int>& b, int n,int m) 
    {
        int ans=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=0;
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }

    int findLength(vector<int>& a, vector<int>& b) {
        memset(dp,-1,sizeof dp);
        int n=a.size();
        int m=b.size();
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=m;j++) dp[0][j]=0;
        return sol(a,b,n,m);
    }
};
