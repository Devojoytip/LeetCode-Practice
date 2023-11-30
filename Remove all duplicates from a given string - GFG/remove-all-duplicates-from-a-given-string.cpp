//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string s) {
	    // code here
	    unordered_map<char, int> exists;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (exists.find(s[i]) == exists.end()) {
                ans.push_back(s[i]);
                exists[s[i]]++;
            }
        }
        return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends