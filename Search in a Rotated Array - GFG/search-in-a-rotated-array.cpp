//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int a[], int l, int h, int k){
        
        int s=l,e=h;
        
        while(s<=e)
        {
            int m=(s+e)/2;
            
            if(a[m]==k) return m;
            
            if(a[s]<=a[m])
            {
                if(a[s]<=k and k<a[m]) e=m-1;
                else s=m+1;
            }
            
            else
            {
                if(a[m]<k and k<=a[e]) s=m+1;
                else e=m-1;
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends