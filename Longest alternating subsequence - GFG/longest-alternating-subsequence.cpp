//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
	public:
		int f(vector<int>&v, int i, int prev, bool b){
		    // Code here
		    
		    if(i>=v.size()) return 0;
		    
		    int take=0, notTake=0;
		    
		    if(b)
		    {
		        if(prev==-1 or v[i]>v[prev]) take=1+f(v,i+1,i,0);
		        notTake=f(v,i+1,prev,b);
		    }
		    
		    else
		    {
		        if(v[i]<v[prev]) take=1+f(v,i+1,i,1);
		        notTake=f(v,i+1,prev,b);
		    }
		    
		    return max(take, notTake);
		}
		
		int AlternatingaMaxLength(vector<int>&v){
		    // Code here
		    
		    int dec=1, inc=1;
		    
		    for(int i=1;i<v.size();i++)
		    {
		        if(v[i]>v[i-1]) inc=dec+1;
		        
		        else if(v[i]<v[i-1]) dec=inc+1;
		        
		    }
		    
		    return max(inc, dec);
		  //  return f(v,0,-1,1);
		}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends