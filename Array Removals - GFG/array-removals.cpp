//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& v, int k){
        //Code here
        sort(v.begin(), v.end());
        
        int n=v.size(), ans=1e9;
        
        if(n==1) return 0;
        
        for(int i=0;i<n;i++)
        {
            int j=upper_bound(v.begin()+i, v.end(), k+v[i])-v.begin()-1;
            ans=min(ans, n-(j-i+1));
        }
        
        return ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends