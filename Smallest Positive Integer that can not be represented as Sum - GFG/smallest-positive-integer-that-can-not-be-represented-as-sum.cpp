//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution
{   
public:
    long long smallestpositive(vector<long long> v, int n)
    { 
        /*
        
        // DP
        
        long long sum=0;
        for(auto it: v) sum+=it;
        
        vector<int> dp(sum+1, 0);
        dp[0]=1;
        
        for(int i=1;i<n;i++)
        {
            // for(int j=sum;j>=v[i-1];j--)
            for(int j=v[i-1];j<=sum;j++)
            {
                if(dp[j-v[i-1]]) dp[j]=1;
            }
        }
        
        for(int j=1;j<=sum;j++) 
        {
            if(!dp[j]) return j;
        }
        
        return sum+1;
        
        */
        
        long long  sum=1;
        sort(v.begin(),v.end());
        
        for(auto it:v)
        {
            if(sum<it) return sum;
            sum+=it;
        }
        
        return sum;
    } 
};


//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<long long> array(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>array[i];
        }
        Solution ob;
        cout<<ob.smallestpositive(array,n)<<"\n";
    }
    return 0; 
} 

// } Driver Code Ends