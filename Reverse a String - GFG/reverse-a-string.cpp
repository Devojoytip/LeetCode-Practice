//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    void recur(string &s, int i, int j)
    {
        // Your code goes here
        if(i==j or i>j) return;
        
        swap(s[i], s[j]);
        
        recur(s,i+1,j-1);
    }
    
    string reverseWord(string s)
    {
        // Your code goes here
        recur(s,0,s.size()-1);
        
        return s;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends