// https://leetcode.com/problems/largest-number 

class Solution {
public:
    string largestNumber(vector<int>& v) {
        
        sort(v.begin(),v.end(),[](const int &a, const int &b)
        {
            string s1=to_string(a);
            string s2=to_string(b);

            return s1+s2 > s2+s1; // as 2+10=210 > 10+2=102
        });

        string ans="";

        for(int it: v) ans+=to_string(it);

        if(ans[0]=='0') return "0";

        return ans;
    }
};
