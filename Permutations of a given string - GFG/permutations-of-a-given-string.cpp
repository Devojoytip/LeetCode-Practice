//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	    void f(string s, string t, vector<string> &res, int cnt, vector<int> vis)
	    {
	        if(cnt==s.size())
	        {
	            res.push_back(t);
	            return;
	        }
	        
	       // for unique permutation ensure same char does not come at the same index/position 
	       
	       unordered_map<char,int> curr_vis;
	       
	       for(int i=0;i<s.size();i++)
	       {
	           if(curr_vis[s[i]] or vis[i]) continue;
	           
	           curr_vis[s[i]]=1;
	           vis[i]=1;
	           f(s,t+s[i],res,cnt+1,vis);
	           vis[i]=0;
	       }
	    }
	    
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    vector<string> res;
		    vector<int> vis(26,0);
		    f(s,"",res,0,vis);
		    
		    sort(res.begin(),res.end(),[](const string &a, const string &b)
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