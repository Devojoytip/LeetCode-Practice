//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    class myClass
    {
        public:
        bool operator()(const pair<int,string> &a, const pair<int,string> &b)
        {
            return a.first>b.first;
        }
    };
    
    string secFrequent (string a[], int n)
    {
        //code here.
        map<string,int> mp;
        
        for(int i=0;i<n;i++) mp[a[i]]++;
        
        priority_queue<pair<int,string> , vector<pair<int,string>>, myClass> pq;
        
        for(auto it: mp)
        {
            pq.push({it.second, it.first});
            
            if(pq.size()>2) pq.pop();
        }
        
        return (pq.size()>1) ? pq.top().second : "";
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends