//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:

    int smallestSubWithSum(int a[], int n, int x)
    {
        // Your code goes here  
        int i=0,j=0,sum=0,ans=1e9;
        
        while(j<n)
        {
            sum+=a[j];
            
            if(sum>x) 
            {
                
                while(sum>x and i<=j)
                {
                    ans=min(ans,j-i+1);
                    sum-=a[i];
                    i++;
                }
                j++;
            }
            else j++;
        }
        
        return (ans==1e9) ? 0 : ans;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends