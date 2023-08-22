//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
		
	public:
	
	int maxSumIS(int a[], int n)  
	{  
	    // Your code goes here
	    int ans=INT_MIN;
	    
	    vector<int> dp(n+1);
	    
	    for(int i=0;i<n;i++) dp[i]=a[i];
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int prev=0;prev<i;prev++)
	        {
	            if(a[prev]<a[i]) dp[i]=max(dp[i], dp[prev]+a[i]);
	        }
	    }
	    
	    for(int i=0;i<n;i++) ans=max(ans, dp[i]);
	    
	    return ans;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends