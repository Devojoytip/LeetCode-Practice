//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > v, int n, int m) {
	    // code here
	    
	    int ans=-1, maxi=-1;
	    
	    for(int i=0;i<n;i++)
	    {
	        int s=0, e=m-1;
	        
	        while(s<=e)
	        {
	            int mid=(s+e)/2;
	            
	            if(v[i][mid]==1 and (mid==0 or v[i][mid-1]==0)) 
	            {
	                if(maxi<m-mid)
	                {
	                    maxi=m-mid;
	                    ans=i;
	                }
	                break;
	            }
	            else if(v[i][mid]==0) s=mid+1;
	            
	            else e=mid-1;
	        }
	    }
	    
	    return ans;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends