//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int f(int a[], int mid, int n) 
    {
        //code here
        int pages=0, cnt=1;
        
        for(int i=0;i<n;i++)
        {
            if(pages+a[i]<=mid) pages+=a[i];
            
            else 
            {
                pages=a[i];
                cnt++;
            }
        }
        
        return cnt;
    }
    
    int findPages(int a[], int n, int m) 
    {
        if (m > n) return -1;
        
        int maxi=0, sum=0;
        
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,a[i]);
            sum+=a[i];
        }
        
        int ans=INT_MAX, s=maxi, e=sum;
        
        while(s<=e)
        {
            int mid=(s+e)/2;
            
            int students=f(a,mid,n);
            
            if(students<=m) e=mid-1;
            
            else s=mid+1;
        }
        
        return s;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends