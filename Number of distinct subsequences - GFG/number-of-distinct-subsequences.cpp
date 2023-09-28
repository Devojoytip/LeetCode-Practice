//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    
	    unordered_map<char, int> mp;
	    int n=s.size();
	    const int mod=1000000007;
	    vector<int> dp(n+1, 0);
	    dp[0]=1;
	    
	    for(int i=0;i<n;i++)
	    {
	        dp[i+1]=(dp[i]*2)%mod;
	        char c=s[i];
	        
	        if(mp.find(c)!=mp.end())
	        {
	            int idx=mp[c];
	            dp[i+1]-=dp[idx];
	        }
	        
	        if(dp[i+1]<=0) dp[i+1]+=mod;
	        
	        mp[c]=i;
	    }
	    
	    return dp[n];
	}
};


//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends