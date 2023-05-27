// https://leetcode.com/problems/letter-case-permutation/description/

class Solution {
public:
    void recur(vector<string> &res,string s,string curr,int idx) {
        if(idx==s.size())
        {
            res.push_back(curr);
            return;
        }
        recur(res,s,curr,idx+1);

        char ch=curr[idx];
        if(isalpha(ch))
        {
            if(isupper(ch)) curr[idx]=tolower(ch);
            else curr[idx]=toupper(ch);
            recur(res,s,curr,idx+1);
        }

    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        string curr=s;
        recur(res,s,curr,0);
        return res;
    }
};
