// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int i=0, j=0, ans=0;
        unordered_map<char, int> mp;

        while(j<s.size())
        {
            char c=s[j];

            if(mp.find(c)!=mp.end())
            {
                while(i<j and s[i]!=c)
                {
                    mp.erase(s[i]);
                    i++;
                }
                i++;
                j++;
            }

            else
            {
                mp[c]=1;
                ans=max(ans, j-i+1);
                j++;
            }
        }

        return ans;
    }
};
