// https://leetcode.com/problems/shortest-common-supersequence

class Solution {
public:
    int dp[1001][1001];
    
    string sol(string a, string b,int i, int j) {
        string res="";
        
        while(i>0 and j>0)
        {
            if(a[i-1]==b[j-1])
            {
                res+=a[i-1];
                i--;
                j--;
            }

            // go to max direction and include the element
            else if(dp[i-1][j]>dp[i][j-1]) 
            {
                res+=a[i-1];
                i--;
            }
            else
            {
                res+=b[j-1];
                j--;
            }
        }
        
        // iterate over both the strings if remaining
        while(i>0)
        {
            res+=a[i-1];
            i--;
        }
       
        while(j>0)
        {
            res+=b[j-1];
            j--;
        }
        
        reverse(res.begin(),res.end());
        return res;
    }

    string shortestCommonSupersequence(string a, string b) {
        
        memset(dp,0,sizeof dp);
        int m=a.length();
        int n=b.length();
        
        // LCS Code
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return sol(a,b,m,n);
    }
};
