//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    int kthElement(int v[], int u[], int m, int n, int k)
    {
        if(k>n+m) return -1;
        
        if(m>n) return kthElement(u,v,n,m,k);
        
        int s=max(0, k-n), e=min(k,m);
        
        while(s<=e)
        {
            int c1=(s+e)/2;
            int c2=k-c1;
            
            int l1=(c1==0)?INT_MIN:v[c1-1];
            int l2=(c2==0)?INT_MIN:u[c2-1];
            
            int r1=(c1==m)?INT_MAX:v[c1];
            int r2=(c2==n)?INT_MAX:u[c2];
            
            if(l1<=r2 and l2<=r1) return max(l1, l2);
            
            if(l1>r2) e=c1-1;
            
            else s=c1+1;
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends