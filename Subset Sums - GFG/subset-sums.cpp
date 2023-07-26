//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{
public:
    void f(vector<int> v, int n, int sum, int i, vector<int> &res)
    {
        // Write Your Code here
        if(i==n) 
        {
            res.push_back(sum);
            return;
        }
        
        f(v,n,sum,i+1,res);
        
        f(v,n,sum+v[i],i+1,res);
    }
    
    vector<int> subsetSums(vector<int> v, int n)
    {
        // Write Your Code here
        vector<int> res;
        f(v,n,0,0,res);
        
        return res;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends