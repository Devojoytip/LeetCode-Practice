//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
	public:
		string FirstNonRepeating(string s)
		{
		    // Code here
		    
		    string res="";
		    vector<int> freq(26, 0);
		    vector<int> v;
		    int n=s.size();
		    
		    for(int i=0;i<n;i++)
		    {
		        char c=s[i];
		        int idx=c-'a';
		         
		        if(freq[idx]==0) v.push_back(c);
		        freq[idx]++;
		        
		        bool flag=0;
		        
		        for(int j=0;j<v.size();j++)
		        {
		            if(freq[v[j]-'a']==1) 
		            {
		                res+=v[j];
		                flag=1;
		                break;
		            }
		        }
		        
		        if(!flag) res+="#";
		        
		    }
		    
		    return res;
		}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends