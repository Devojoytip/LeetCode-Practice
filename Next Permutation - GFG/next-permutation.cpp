//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> v){
        // code here
        int idx=-1;
        
        for(int i=n-2;i>=0;i--)
        {
            if(v[i]<v[i+1])
            {
                idx=i;
                break;
            }
        }
        
        for(int i=n-1;i>=0 and idx!=-1;i--)
        {
            if(v[idx]<v[i])
            {
                swap(v[idx], v[i]);
                break;
            }
        }
        
        reverse(v.begin()+idx+1,v.end());
        
        return v;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends