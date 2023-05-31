/*
https://leetcode.com/problems/optimal-partition-of-string
*/

class Solution {
public:
    int partitionString(string s) {
        int i=0,j=0,ans=0;
        map<char,bool> mp;

        while(j<s.size())
        {
            char ch=s[j];

            if(mp.find(ch)!=mp.end())
            {
                ans++;
                while(i!=j)
                {
                    mp.erase(s[i]);
                    i++;
                }
                i=j;
                mp.erase(s[i]);
            }
            else 
            {
                mp[ch]=1;
                j++;
            }
        }
        ans++;
        return ans;
    }
};
