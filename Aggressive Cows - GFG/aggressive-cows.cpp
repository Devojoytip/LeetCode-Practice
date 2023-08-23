//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool f(vector<int> &v, int mid, int k)
    {
        int last=v[0], cows=1;
        
        for(int i=1;i<v.size();i++)
        {
            if(v[i]-last>=mid)
            {
                last=v[i];
                cows++;
            }
            
            if(cows==k) return 1;
        }
        
        return 0;
    }

    int solve(int n, int k, vector<int> &v) {
    
        // Write your code here
        sort(v.begin(),v.end());
        
        int s=1, e=v.back()-v.front(); 
        
        while(s<=e)
        {
            int mid=(s+e)/2;
            
            bool canPlace=f(v,mid,k);
            
            if(canPlace) s=mid+1;
            else e=mid-1;
        }
        
        return e;
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends