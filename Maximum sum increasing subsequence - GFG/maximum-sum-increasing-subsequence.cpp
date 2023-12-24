//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int a[], int n)  
	{  
	    // Your code goes here
	    int dp[n+1]={0}, ans=0;
	    
	    for(int curr=0;curr<n;curr++)
	    {
	        dp[curr]=a[curr];
	        
	        for(int prev=0;prev<curr;prev++)
	        {
	            if(a[curr]>a[prev]) dp[curr]=max(dp[curr], a[curr]+dp[prev]);
	        }
	        
	        ans=max(ans, dp[curr]);
	    }
	    
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