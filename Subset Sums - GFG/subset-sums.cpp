//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{
public:
    void f(vector<int> v, vector<int> &res, int n, int i, int sum)
    {
        // Write Your Code here
        if(i==v.size())
        {
            res.push_back(sum);
            return;
        }
        
        f(v,res,n,i+1,sum);
        
        sum+=v[i];
        f(v,res,n,i+1,sum);
    }
    
    vector<int> subsetSums(vector<int> v, int n)
    {
        // Write Your Code here
        vector<int> res;
        f(v,res,n,0,0);
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