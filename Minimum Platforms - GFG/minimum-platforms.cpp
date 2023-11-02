//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int a[], int d[], int n)
    {
    	// Your code here
    	vector<pair<int,int>> v;
    	
    	int dd=0,ans=0;
    	
    	for(int i=0;i<n;i++) v.push_back({a[i],d[i]});
    	
    	sort(v.begin(),v.end());
    	
    	vector<int> u(n, -1);
    	
    	for(auto it: v)
    	{
    	    for(int i=0;i<n;i++)
    	    {
    	        if(u[i]<it.first)
    	        {
    	            if(u[i]==-1) ans++;
    	            u[i]=it.second;
    	            break;
    	        }
    	    }
    	}
    	
    	return ans;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends