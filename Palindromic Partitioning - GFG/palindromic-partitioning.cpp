//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int dp[505][505];
    int pal[505][505];
    
    bool isPal(string s,int i,int j)
    {
        if(pal[i][j]!=-1) return pal[i][j];
        
        if(i==j) return pal[i][j]=1;
        int x=i, y=j;
        
        while(i<j)
        {
            if(s[i]==s[j]) i++, j--;
            else return pal[x][y]=0;
        }
        
        return pal[x][y]=1;
    }
    
    int sol(string s,int i,int j)
    {
        if(i>j)return dp[i][j]=1e8;
        
        if(i==j)return dp[i][j]=0;
        
        if(pal[i][j]==1 or isPal(s,i,j)) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=INT_MAX;
        
        for(int k=i;k<j;k++)
        {
            int left,right;
            
            if(dp[i][k]!=-1) left=dp[i][k];
            //else if(pal[i][k]==1 or isPal(s,i,k)) left=0;
            else left=sol(s,i,k);
            
            if(dp[k+1][j]!=-1) right=dp[k+1][j];
            //else if(pal[k+1][j]==1 or isPal(s,k+1,j)) right=0;
            else right=sol(s,k+1,j);
            
            ans=min(ans,left+right+1);
        }
        
        return dp[i][j]=ans;
    }
    
    int palindromicPartition(string s) {
        memset(dp,-1,sizeof dp);
        memset(pal,-1,sizeof dp);
        return sol(s,0,s.length()-1);
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends