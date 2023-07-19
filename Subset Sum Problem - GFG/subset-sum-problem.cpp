//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool f(vector<int>v, int i, int n, int s, vector<vector<int>> &dp){
        // code here 
        if(s==0) return 1;
        
        if(i==n) return 0;
        
        if(dp[i][s]!=-1) return dp[i][s];
        
        if(v[i]<=s) dp[i][s]= f(v,i+1,n,s,dp) or f(v,i+1,n,s-v[i],dp);
        
        else dp[i][s]= f(v,i+1,n,s,dp);
        
        return dp[i][s];
    }
    
    bool isSubsetSum(vector<int>v, int sum){
        // code here 
        int n=v.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1,-1));
        return f(v,0,n,sum,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends