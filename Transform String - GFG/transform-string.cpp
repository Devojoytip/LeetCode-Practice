//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    int transform (string a, string b)
    {
        //code here.
        
        if(a.size()!=b.size()) return -1;
        
        int ans=0;
        
        if(a==b) return ans;
        
        unordered_map<char, int> mp;
        
        for(auto c: a) mp[c]++;
        
        for(auto c: b) mp[c]--;
        
        for(auto it: mp)
        {
            if(it.second!=0) return -1;
        }
        
        int i=a.size()-1, j=b.size()-1;
        
        while(i>=0 and j>=0)
        {
            if(a[i]==b[j]) i--, j--;
            
            else ans++, i--;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends