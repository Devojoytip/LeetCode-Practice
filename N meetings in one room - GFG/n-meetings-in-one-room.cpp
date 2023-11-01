//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool cmp(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
    {
        if(a.second.second != b.second.second) return a.second.second < b.second.second;
        
        return a.second.first < b.second.first;
    }
    
    int maxMeetings(int s[], int e[], int n)
    {
        // Your code here
        
        vector<pair<int, pair<int, int>>> v;
        
        for(int i=0;i<n;i++) v.push_back({i, {s[i], e[i]}});
        
        sort(v.begin(), v.end(), cmp);
        
        int end=0, ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(end<v[i].second.first)
            {
                end=v[i].second.second;
                ans++;
            }
        }
        
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
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends