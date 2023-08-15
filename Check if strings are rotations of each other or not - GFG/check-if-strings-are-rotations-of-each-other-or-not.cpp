//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    
    unordered_map<string, int> mp;
    
    // bool f(string a,string b)
    // {
    //     // Your code here
    //     if(a==b) return 1;
        
    //     if(a=="" and b=="") return 1;
        
    //     if(a.size()!=b.size()) return 0;
        
    //     string key=a+"."+b;
        
    //     if(mp.find(key)!=mp.end()) return mp[key];
        
    //     bool ans=0;
        
    //     for(int k=0;k<a.size()-1;k++)
    //     {
    //         if(f(a.substr(0,k+1), b.substr(0,k+1)) and f(a.substr(k+1), b.substr(k+1))) 
    //         {
    //             ans=1;
    //             break;
    //         }
            
    //         if(f(a.substr(0,k+1), b.substr(a.size()-k-1,a.substr(0,k+1).size())) and f(a.substr(k+1), b.substr(0, a.substr(k+1).size()))) 
    //         {
    //             ans=1;
    //             break;
    //         }
    //     }
        
    //     return mp[key]=ans;
    // }
    
    bool f(string a,string b)
    {
        if(a==b) return 1;
        
        if(a.size()!=b.size()) return 0;
        
        for(int i=0;i<a.size()-1;i++)
        {
            string s1=a.substr(0,i+1);
            string s2=a.substr(i+1);
            string t=s2+s1;
            if(t==b) return 1;
        }
        
        return 0;
    }
    
    bool areRotations(string a,string b)
    {
        // Your code here
        mp[a]=1;
        mp[b]=1;
        return f(a,b);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends