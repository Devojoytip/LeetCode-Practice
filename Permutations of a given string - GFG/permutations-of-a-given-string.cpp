//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
		void f(string s, string curr, int cnt, vector<string> &res, vector<int> &vis)
		{
		    // Code here there
		    if(cnt==s.size())
		    {
		        res.push_back(curr);
		        return;
		    }
		    
		    unordered_map<char, int> mp; // ensure same char doesn't come again
		    
		    for(int i=0;i<s.size();i++)
		    {
		        if(mp.find(s[i])!=mp.end() or vis[i]) continue;
		        mp[s[i]]=1;
		        vis[i]=1;
	            cnt++;
	            f(s,curr+s[i],cnt,res,vis);
	            vis[i]=0;
	            cnt--;
		    }
		}
		
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    vector<string> res;
		    vector<int> vis(26, 0);
		    f(s,"",0,res,vis);
		    sort(res.begin(), res.end(), [](const string &a, const string &b)
		    {
		        return a<b;
		    });
		    return res;
		}
};


//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends