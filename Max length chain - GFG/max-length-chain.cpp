//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
    /*You are required to complete this method*/
    static bool cmp(const struct val &a, const struct val &b)
    {
        return a.second<b.second;
    }
    
    int maxChainLen(struct val a[],int n){
        
        sort(a,a+n,cmp);
        
        int i=0, j=1, ans=1;
        
        while(j<n)
        {
            if(a[j].first>a[i].second)
            {
                i=j;
                ans++;
                j++;
            }
            else j++;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends