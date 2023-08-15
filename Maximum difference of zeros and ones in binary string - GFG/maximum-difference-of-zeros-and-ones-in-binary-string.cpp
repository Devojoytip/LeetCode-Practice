//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// Kadane's Algo

class Solution{
public:	
	int maxSubstring(string s)
	{
	    // Your code goes here
	    int ans=-1e9, diff=0;
	    
	    for(int i=0;i<s.size();i++)
	    {
	        int j=(s[i]=='1') ? -1 : 1;
	        diff+=j;
	        ans=max(ans, diff);
	        if(diff<0) diff=0;
	    }
	    
	    return ans;
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

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends