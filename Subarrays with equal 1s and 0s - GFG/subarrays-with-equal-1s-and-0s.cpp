//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int a[], int n)
    {
        //Your code here
        long ans=0, sum=0;
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            if(a[i]==0) a[i]=-1;
            sum+=a[i];
            
            if(sum==0) ans++;
            
            if(mp[sum]) ans+=mp[sum];
            
            mp[sum]++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}

// } Driver Code Ends