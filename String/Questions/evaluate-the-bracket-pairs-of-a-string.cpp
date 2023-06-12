// https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& v) {
        
        map<string , string> mp;

        for(int i=0 ; i<v.size() ; i++) mp[v[i][0]] = v[i][1];

        string res="";
        int i=0;

        while(i<s.size())
        {
            if(s[i]=='(')
            {
                int start=i;
                string key="";
                string val="?";
                i++;
                while(s[i]!=')') 
                {
                    key+=s[i];
                    i++;
                }

                if(mp.find(key)!=mp.end()) val=mp[key];
                res+=val;
                i=start+key.size()+2;
            }
            else 
            {
                res+=s[i];
                i++;
            }
        }

        return res;
    }
};
