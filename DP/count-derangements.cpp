// https://www.codingninjas.com/studio/problems/count-derangements_873861?leftPanelTab=1

long long int f(int n, int dp[]) {
    // Write your code here.
    if(n==1) return 0;
    
    if(n==2) return 1;

    if(dp[n]!=-1) return dp[n];

    return dp[n] = (n-1)*(f(n-1,dp)+f(n-2,dp));
}


long long int countDerangements(int n) {
    // Write your code here.
    int mod=1e9+7;

    long dp[n+1];
    dp[1]=0;
    dp[2]=1;

    long a=0, b=0;

    for(int i=3;i<=n;i++)
    {
        dp[i]=((i-1)*(dp[i-1]+dp[i-2]))%mod;
    }

    return dp[n];
}
