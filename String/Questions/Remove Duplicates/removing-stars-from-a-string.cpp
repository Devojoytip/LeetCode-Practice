// https://leetcode.com/problems/removing-stars-from-a-string

class Solution {
public:
    string removeStars(string s) {      
        
        string res;

        for(int i=0;i<s.size();i++)
        {
            if(res.size() and s[i]=='*') res.pop_back();

            else if(s[i]!='*') res.push_back(s[i]);
        }

        return res;
    }
};
