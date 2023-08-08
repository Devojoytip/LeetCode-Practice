//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int a[], int n) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        
        vector<int> res(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(pq1.size()<k) 
            {
                pq1.push(a[i]);
                if(pq1.size()==k) res[i]=pq1.top();
            }
            else
            {
                if(pq1.top()<a[i])
                {
                    pq1.push(a[i]);
                    pq2.push(pq1.top());
                    pq1.pop();
                }
                else pq2.push(a[i]);
                res[i]=pq1.top();
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends