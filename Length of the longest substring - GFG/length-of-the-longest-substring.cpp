//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        int i=0, j=0, ans=0;
        unordered_map<char, int> mp;
        
        while(j<s.size())
        {
            char c=s[j];

            if(mp[c]==1)
            {
                while(i<=j)
                {
                    if(s[i]==c) break;
                    mp[s[i]]--;
                    i++;
                }
                i++;
                j++;
            }

            else
            {
                mp[c]=1;
                ans=max(ans, j-i+1);
                j++;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends