// https://leetcode.com/problems/number-of-matching-subsequences

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& v) {
        unordered_map<char,vector<int>> mp;

        for(int i=0;i<s.size();i++) mp[s[i]].push_back(i);

        int ans=0;

        for(auto it: v)
        {
            int prev=-1;
            bool flag=1;

            for(int i=0;i<it.size();i++)
            {
                char c=it[i];
                if(mp.find(c)==mp.end())
                {
                    flag=0;
                    break;
                }
                if(upper_bound(mp[c].begin(),mp[c].end(),prev)==mp[c].end())
                {
                    flag=0;
                    break;
                }

                int idx=upper_bound(mp[c].begin(),mp[c].end(),prev)-mp[c].begin();
                prev=mp[c][idx];
            }

            if(flag) ans++;
        }

        return ans;
    }
};
