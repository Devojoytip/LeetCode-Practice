//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> s, vector<int> e, int n)
    {
        // Your code here
        vector<pair<int, int>> v;
        
        for(int i=0;i<n;i++) v.push_back({e[i], s[i]});
        
        sort(v.begin(), v.end());
        
        int ans=0, end=-1;
        
        for(int i=0;i<n;i++)
        {
            if(end<v[i].second)
            {
                end=v[i].first;
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