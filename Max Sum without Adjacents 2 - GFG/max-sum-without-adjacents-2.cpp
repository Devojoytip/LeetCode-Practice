//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  int f(vector<int>& v, int i, vector<int>& dp)
  {
      if(i>=v.size()) return 0;
      
      if(i==v.size()-1) return v[i];
      
      if(i==v.size()-2) return v[i]+v[i+1];
      
      if(dp[i]!=-1) return dp[i];
      
      return dp[i] = max({v[i]+v[i+1]+f(v,i+3,dp), v[i]+f(v,i+2,dp), f(v,i+1,dp)});
  }
  
  int findMaxSum(vector<int>& v){
      //Code Here
      int n=v.size();
      vector<int> dp(n+1,-1);
      return f(v,0,dp);
  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends