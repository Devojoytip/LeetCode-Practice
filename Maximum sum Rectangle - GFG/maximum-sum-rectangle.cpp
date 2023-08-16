//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int r, int c, vector<vector<int>> v) {
        // code here
        vector<int> u(r,0);
        int ans=INT_MIN;
        
        for(int cs=0;cs<c;cs++)
        {
            // Init u with 0s
            for(int i=0;i<r;i++) u[i]=0;
            
            for(int ce=cs;ce<c;ce++)
            {
                for(int i=0;i<r;i++) 
                {
                    u[i]+=v[i][ce];
                }
                
                int sum=Kadanes(u, r);
                ans=max(ans, sum);
            }
        }
        
        return ans;
    }
    
    int Kadanes(vector<int> u, int r)
    {
        int sum=0, ans=u[0];
        
        for(int i=0;i<r;i++)
        {
            sum+=u[i];
            ans=max(ans, sum);
            if(sum<0) sum=0;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends