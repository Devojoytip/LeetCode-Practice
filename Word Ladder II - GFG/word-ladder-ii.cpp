//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

// BFS
class Solution
{
public:
    vector<vector<string>> findSequences(string s, string e, vector<string> &v)
    {
        set<string> st;
        for (int i=0; i<v.size(); i++) st.insert(v[i]);

        queue<vector<string>> q;
        vector<string> u;
        vector<string> used;
        vector<vector<string>> res;
        u.push_back(s);
        used.push_back(s);
        q.push(u);
        int found=0,len,level=0;

        while (!q.empty())
        {
            vector<string> u = q.front();
            q.pop();
            string curr=u.back();
            if(u.size()>level)
            {
                for(auto it:used) st.erase(it);
                level++;
            }

            if (curr == e) 
            {
                res.push_back(u);
                len=u.size();
                found=1;
                continue; 
            }

            if(found and len>=u.size()) continue;

            for (int i = 0; i < curr.size(); i++)
            {
                for (char ch='a';ch<='z';ch++)
                {
                    string temp = curr;
                    temp[i] = ch;
                    
                    if (st.find(temp)!=st.end())
                    {
                        u.push_back(temp);
                        used.push_back(temp);
                        q.push(u);
                        u.pop_back();
                    }
                }
            }
        }

        return res;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends