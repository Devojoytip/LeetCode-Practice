//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends

class Solution{
    public:
    void f(string &s, int i)
    {
        // code here.
        if(s.size()==0 or s.size()==1 or i==s.size()) return;
        
        if(i>0 and s[i]==s[i-1]) 
        {
            s.erase(i,1);
            f(s,i);
            return;
        }
        else f(s,i+1);
    }
    string removeConsecutiveCharacter(string s)
    {
        // code here.
        f(s,0);
        return s;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends