//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& v) {
        // Code here
        vector<int> dp(n,1); // each single ele is LIS of len = 1, dp[i]=length of lis ending at v[i]
        vector<int> hash(n,1); // to store index of prev for printing lis
        vector<int> res;
        
        for(int i=0;i<n;i++) hash[i]=i;
        
        int ans=0,lis_idx;
        
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(v[prev]<v[i] and dp[i]<1+dp[prev]) 
                {
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>ans)
            {
                ans=dp[i];
                lis_idx=i;
            }
        }
        
        while(hash[lis_idx]!=lis_idx)
        {
            res.push_back(v[lis_idx]);
            lis_idx=hash[lis_idx];
        }
        res.push_back(v[lis_idx]);
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends