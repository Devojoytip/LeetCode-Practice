//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    long long findRank(string s) {
        //code here
        vector<int> v(26,0);
        
        for(auto c:s) v[c-'a']++;
        
        int n=s.size();
        long long ans=1;
        
        vector<long long> fact(n+1, 0);
        fact[0]=1, fact[1]=1;
        
        for(int i=2;i<=n;i++) fact[i]=i*fact[i-1];
        
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            int countSmaller=0;
            
            for(int j=0;j<c-'a';j++) countSmaller+=v[j];
            
            ans+=countSmaller*fact[n-1-i];
            
            v[c-'a']--;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends