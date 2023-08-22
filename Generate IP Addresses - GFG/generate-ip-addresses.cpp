//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    
    void recur(vector<string> &res, int dots, int i, string s, string temp,string t)
    {

        if(i>=s.size())
        {
            if(dots>0) return;
            if((t[0]=='0' and t!="0") or t.size()<1 or stoi(t)>255) return;
            temp+=t;
            res.push_back(temp);
            return;
        }

        if(dots<0) return;

        if(t.size()==0) recur(res,dots,i+1,s,temp,t+s[i]);
        
        else
        {
            if(stoi(t)>255) return;
            if(t[0]=='0' and t!="0") return;

            recur(res,dots-1,i,s,temp+t+".","");
            t+=s[i];
            recur(res,dots,i+1,s,temp,t);
        }
    }

    vector<string> genIp(string &s) 
    {
        vector<string> res;
        int dots=3;
        recur(res,dots,0,s,"","");
        return res;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends