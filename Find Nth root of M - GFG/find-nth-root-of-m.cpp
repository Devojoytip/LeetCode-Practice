//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	int f(int num, int n, int m)
	{
	    long long int ans=1;
	    
	    for(int i=1;i<=n;i++)
	    {
	        ans*=num;
	        if(ans>m) return 2;
	        if(ans==m and i==n) return 1;
	    }
	    
	    return 0;
	}
	
	int recur(int n, int m)
	{
	    // Code here.
	    int s=1, e=m;
	    
	    while(s<=e)
	    {
	        int mid=(s+e)/2;
	        
	        int res=f(mid,n,m);
	        
	        if(res==1) return mid;
	        
	        if(res==2) e=mid-1;
	        
	        else s=mid+1;
	    }
	    
	    return -1;
	}  
	
	int NthRoot(int n, int m)
	{
	    // Code here.
	    return recur(n,m);
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends