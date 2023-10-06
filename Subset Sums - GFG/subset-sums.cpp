//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> v, int n)
    {
        // Write Your Code here
        vector<int> res;
        f(v,res,0,0,n);
        return res;
    }
    
    void f(vector<int> v, vector<int> &res, int sum, int i, int n)
    {
        if(i==n)
        {
            res.push_back(sum);
            return;
        }
        
        f(v,res,sum,i+1,n);
        f(v,res,sum+v[i],i+1,n);
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