// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:
    bool pal(string s)
    {
        string a=s;
        reverse(s.begin(),s.end());
        return a==s;
    }

    void f(string s, int i, vector<string> curr, vector<vector<string>> &res, bool take) {
        
        if(i==s.size()) 
        {
            if(flag) res.push_back(curr);
            return;
        }

        string t=s.substr(0,i+1);

        if(pal(t))
        {
            curr.push_back(t);
            f(s.substr(i+1),0,curr,res,1);
            curr.pop_back();
        }
        
        f(s,i+1,curr,res,0);
    }

    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> res;

        f(s,0,{},res,0);

        return res;
    }
};
