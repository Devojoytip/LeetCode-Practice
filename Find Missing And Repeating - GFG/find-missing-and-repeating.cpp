//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> A, int n) {
        // code here
        long long int len = A.size();
        long long int Sum_N = (len * (len+1) ) /2, Sum_NSq = (len * (len +1) *(2*len +1) )/6;
        long long int missingNumber=0, repeating=0;
         
        for(int i=0;i<A.size(); i++){
           Sum_N -= (long long int)A[i];
           Sum_NSq -= (long long int)A[i]*(long long int)A[i];
        }
         
        missingNumber = (Sum_N + Sum_NSq/Sum_N)/2;
        repeating= missingNumber - Sum_N;
        vector <int> ans;
        ans.push_back(repeating);
        ans.push_back(missingNumber);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends