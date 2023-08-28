// https://leetcode.com/problems/determine-if-two-strings-are-close

class Solution {
public:
    bool closeStrings(string s1, string s2) {
        
        if(s1.size()!=s2.size()) return 0;
        
        vector<int>v(26),u(26);
        
        for(auto i:s1) v[i-'a']++;
        
        for(auto i:s2) u[i-'a']++;
        
        for(int i=0;i<26;i++)
        {
            if((v[i]==0 and u[i]!=0) or (u[i]!=0 and v[i]==0)) return 0;
        }
        
        sort(v.begin(),v.end());

        sort(u.begin(),u.end());

        for(int i=0;i<26;i++)
        {
            if(v[i]!=u[i]) return 0;
        }
        
        return 1;
    }
};
