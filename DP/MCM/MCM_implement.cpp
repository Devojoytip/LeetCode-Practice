// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution{
public:
    int dp[101][101];
    int MCM(int a[], int i, int j)
    {
        // code here
        int ans=INT_MAX;
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i;k<=j-1;k++)
        {
            int temp=MCM(a,i,k) + MCM(a,k+1,j) + a[i-1]*a[k]*a[j];
            ans=min(ans,temp);
        }
        
        return dp[i][j]=ans;
    }
    
    int matrixMultiplication(int n, int a[])
    {
        // code here
        memset(dp,-1,sizeof dp);
        return MCM(a,1,n-1);
    }
};
