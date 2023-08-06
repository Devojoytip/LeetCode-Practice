//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    ll merge(ll a[], ll s, ll mid, ll e, ll n)
    {
        ll i=s, j=mid+1, cnt=0;
        
        while(i<=mid)
        {
            cnt+=j-(mid+1);
            while(j<=e and a[i]>a[j]) cnt++,j++;
            i++;
        }
        
        vector<ll> v;
        i=s; 
        j=mid+1;
        
        while(i<=mid and j<=e)
        {
            if(a[i]<a[j])
            {
                v.push_back(a[i]);
                i++;
            }
            else
            {
                v.push_back(a[j]);
                j++;
            }
        }
        
        while(i<=mid)
        {
            v.push_back(a[i]);
            i++;
        }
        
        while(j<=e)
        {
            v.push_back(a[j]);
            j++;
        }
        
        for(ll k=s;k<=e;k++)
        {
            a[k]=v[k-s];
        }
        
        return cnt;
    }
    
    ll mergeSort(ll a[], ll s, ll e, ll n)
    {
        // Your Code Here
        if (s >= e) return 0;
        
        ll mid=(s+e)/2;
        
        ll ans = mergeSort(a,s,mid,n);
        
        ans += mergeSort(a,mid+1,e,n);
        
        ans += merge(a,s,mid,e,n);
        
        return ans;
    }
     
    ll int inversionCount(ll a[], ll n)
    {
        // Your Code Here
        return mergeSort(a,0,n-1,n);
    }

};


//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends