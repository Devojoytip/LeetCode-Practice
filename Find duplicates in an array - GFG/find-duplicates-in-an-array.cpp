//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(long long a[], int n) {
        // code here
        
        int zeros=0;
        vector<int> res;
        
        for(int i=0;i<n;i++) 
        {
            int idx=a[i]%n;
            a[idx]+=n;
        }
        
        for(int i=0;i<n;i++)
        {
            if(a[i]/n>=2) res.push_back(i);
        }
        
        if(res.empty()) return {-1};
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends