//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    
    static bool cmp(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
    {
        if(a.second.second!=b.second.second) return a.second.second<b.second.second;
        
        return a.second.first<b.second.first;
    }
    
    int activitySelection(vector<int> s, vector<int> e, int n)
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
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends