//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&v, int n)
    {   
        // Your code here
        unordered_map<int, int>mp;
        int i=0,sum=0,ans=0;
        
        for (int i = 0; i < n; i++) 
        {
            sum+=v[i];
            
            if(sum==0) ans=max(ans, i+1);
            
            int rem=sum-0;
            
            if(mp.find(sum)!=mp.end()) ans=max(ans, i-(mp[sum]+1)+1);
            
            if(mp.find(sum)==mp.end()) mp[sum]=i;
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
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends