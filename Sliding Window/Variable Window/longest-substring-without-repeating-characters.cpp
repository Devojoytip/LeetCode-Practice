/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,ans=0;
        map<char,int> mp;

        while(j<s.size())
        {
            char ch=s[j];
            if(mp.find(ch)!=mp.end()) 
            {
                while(s[i]!=ch)
                {
                    mp.erase(s[i]);
                    i++;
                }
                mp.erase(ch);
                i++;
            }
            else
            {
                mp[ch]=1;
                ans=max(ans,j-i+1);
                j++;
            }
        }

        return ans;
    }
};
