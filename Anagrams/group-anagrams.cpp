// https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) {

        vector<vector<string>> res;

        map<string,vector<string>> mp;

        for(auto s:v)
        {
            string temp=s;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(s);
        }

        for(auto it:mp)
        {
            vector<string> u;
            for(auto st:it.second)
            {
                u.push_back(st);
            }
            res.push_back(u);
        }

        return res;
    }
};
