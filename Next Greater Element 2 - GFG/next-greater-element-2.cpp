//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int n, vector<int>& v) {
        // code here
        
        stack<int> s;
        vector<int> res(n, -1);
        
        for(int i=n-2;i>=0;i--)
        {
            while(s.size() and s.top()<=v[i]) s.pop();
            s.push(v[i]);
        }
        
        for(int i=n-1;i>=0;i--)
        {
            while(s.size() and s.top()<=v[i]) s.pop();
            res[i]=(s.size())?s.top():-1;
            s.push(v[i]);
        }
        
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
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends