//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int a[], int n){
        //complete the function here
        
        int s=0, e=n-1;
        
        if(a[s]<=a[e]) return a[s]; // sorted & not rotated array
        
        while(s<=e)
        {
            int mid=(s+e)/2;
            
            if(mid>0 and a[mid]<a[mid-1]) return a[mid];
            
            else if(a[mid]>a[e]) s=mid+1;
            
            else e=mid-1;
        }
        
        return -1;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends