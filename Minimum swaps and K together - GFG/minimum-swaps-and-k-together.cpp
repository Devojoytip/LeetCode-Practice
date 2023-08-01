//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int a[], int n, int k) {
        // Complet the function
        
        int good=0, bad=0, ans=1e9, i=0, j=0;
        
        for(int i=0;i<n;i++) 
        {
            if(a[i]<=k) good++;
        }
        
        while(j<n)
        {
            if(a[j]>k) bad++;
            
            if(j-i+1==good) 
            {
                ans=min(ans,bad);
                if(a[i]>k) bad--;
                i++;
            }
            j++;
        }
        
        return (ans==1e9) ? 0 : ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends