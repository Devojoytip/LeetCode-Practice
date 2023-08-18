//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    
    int maxSumPairWithDifferenceLessThanK(int a[], int n, int k)
    {
        // Your code goes here   
        
        sort(a, a+n, greater<int>());
        int i=0, sum=0;
        
        while(i<n-1)
        {
            int diff=abs(a[i]-a[i+1]);
            
            if(diff<k)
            {
                sum+=a[i]+a[i+1];
                i+=2;
            }
            
            else i++;
        }
        
        return sum;
    }
};


//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends