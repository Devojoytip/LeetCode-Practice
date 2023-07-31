//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int n)
    {
        // code here
        vector<int> res;
        int k=1;
        int carry=0;
        
        while(k<=n)
        {
            if(res.empty())
            {
                res.push_back(1);
                continue;
            }
            
            for(int i=0;i<res.size();i++)
            {
                int num=(res[i]*k)+carry;
                res[i]=num%10;
                carry=num/10;
            }
            
            while(carry)
            {
                res.push_back(carry%10);
                carry/=10;
            }
            
            k++;
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends