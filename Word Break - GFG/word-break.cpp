//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int recur(string s, int idx, int n, map<string,bool> mp) {
        //code here
        
        if(idx==n) return 1;
        
        for(int i=idx;i<n;i++)
        {
            string temp = s.substr(idx,i-idx+1);
            if(mp.find(temp)!=mp.end())
            {
                if(recur(s,i+1,n,mp)) return 1;
            }
            
        }
        
        return 0;
    }
    int wordBreak(string s, vector<string> &v) {
        //code here
        map<string,bool> mp;
        int n = s.size();
        for(auto it: v) mp[it]=1;
        
        return recur(s,0,n,mp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends