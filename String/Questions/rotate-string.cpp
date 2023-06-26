// https://leetcode.com/problems/rotate-string/description/

class Solution {
public:
    bool rotateString(string s, string g) {
        
        for(int i=0;i<s.size();i++)
        {
            if(s==g) return 1;
            char ch=s[0];
            s.erase(0,1);
            s.push_back(ch);
        }

        return  0;
    }
};
