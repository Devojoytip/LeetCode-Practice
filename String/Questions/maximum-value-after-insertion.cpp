// https://leetcode.com/problems/maximum-value-after-insertion 

class Solution {
public:
    string maxValue(string s, int x) {

        int len=s.size();
        char ch=x+'0';

        if(s[0]=='-')
        {
            int i=1;
            while(i<s.size() and s[i]<=ch) i++;
            return s.substr(0,i-1-0+1)+ch+s.substr(i);
        }
        for(int i=0;i<len;i++)
        {
            while(i<s.size() and s[i]>=ch) i++;
            return s.substr(0,i)+ch+s.substr(i);
        }

        return "";
    }
};
