// https://practice.geeksforgeeks.org/problems/pattern-searching5231/1

// Check Length of longest common substring == b.size() then b present as it means longest common substring is b itself

bool searchPattern(string a, string b) 
{
    // code here
    
    int n=a.size(), m=b.size(),maxLen=0,endIndex=-1;
    if(n<m) return 0;
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = 0;
            
            if(maxLen < dp[i][j]) maxLen = dp[i][j];
        }
    }
    
    
    return maxLen == b.size();
} 
