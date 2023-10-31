//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string a, string b)
    {
        // Your code here
        int n = a.length();
        bool clockwise = true, anticlockwise = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[(i + 2) % n])
            {
                clockwise = false; // not rotated clockwise
                break;
            }
        }
     
        for (int i = 0; i < n; i++)
        {
            if (a[(i + 2) % n] != b[i])
            {
                anticlockwise = false; // not rotated anticlockwise
                break;
            }
        }
 
    return clockwise or anticlockwise; // if any of both is true, return true
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends