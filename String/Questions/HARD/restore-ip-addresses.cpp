// https://leetcode.com/problems/restore-ip-addresses

class Solution {
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

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int dots=3;
        recur(res,dots,0,s,"","");
        return res;
    }
};
