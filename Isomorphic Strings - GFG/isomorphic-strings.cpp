//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string a, string b)
    {
        
        // Your code here
        unordered_map<char, char> mp;
        unordered_map<char, char> mp1;
        
        int i=0, j=0, n=a.size(), m=b.size();
        
        while(i<n and j<m)
        {
            char c1=a[i], c2=b[j];
            
            if(mp.find(c1)!=mp.end())
            {
                if(mp[c1]!=c2) return 0;
            }
            
            if(mp1.find(c2)!=mp1.end())
            {
                if(mp1[c2]!=c1) return 0;
            }
            
            mp[c1]=c2;
            mp1[c2]=c1;
            i++;
            j++;
        }
        
        if(i==n and j==m) return 1;
        
        while(i<n)
        {
            if(mp.find(a[i])==mp.end()) return 0;
            i++;
        }
        
        while(j<m)
        {
            if(mp1.find(b[j])==mp1.end()) return 0;
            j++;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends