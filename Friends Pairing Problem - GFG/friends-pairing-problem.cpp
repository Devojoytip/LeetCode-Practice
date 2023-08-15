//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

const int mod = 1e9+7;

class Solution
{
public:

    long long int f(int n, vector<long long int> &dp)
    {
        if(n==0) return dp[n]=0;
        
        if(n==1) return dp[n]=1;
        
        if(n==2) return dp[n]=2;
        
        if(dp[n]!=-1) return dp[n];
        
        long long int single=(1*f(n-1,dp))%mod;
        
        long long int pair=((n-1)*f(n-2,dp))%mod;
        
        return dp[n]=(single+pair)%mod;
    }
    
    int countFriendsPairings(int n) 
    { 
        // code here
        vector<long long int> dp(n+1, -1);
        return (int)f(n,dp);
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends