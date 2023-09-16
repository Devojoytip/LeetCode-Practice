//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        
        string res="";
        int n=s.size(), maxLen=0;
        
        for(int i=0;i<n;i++)
        {
            int l=i,r=i+1;
            int evenPal=sol(s,l,r,n);
            
            if(maxLen<evenPal)
            {
                maxLen=evenPal;
                res=s.substr(l+1, evenPal);
            }
            
            l=i,r=i;
            int oddPal=sol(s,l,r,n);
            
            if(maxLen<oddPal)
            {
                maxLen=oddPal;
                res=s.substr(l+1, oddPal);
            }
            
        }
        
        return res;
    }
    
    int sol(string s, int &l, int &r, int n)
    {
        while(l>=0 and r<n and s[l]==s[r]) l--, r++;
        return r-l-1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends