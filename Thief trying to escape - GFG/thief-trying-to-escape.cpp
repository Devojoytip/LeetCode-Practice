//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int totalJumps(int x, int y, int n, int a[]){
        // code here
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(a[i]<x) ans++;
            else
            {
                int net=x-y;
                int rem=a[i]-x;
                
                if(rem%net==0) ans+=1+(rem/net);
                else ans+=1+(rem/net)+1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int X, Y, N;
        cin>>X>>Y>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.totalJumps(X, Y, N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends