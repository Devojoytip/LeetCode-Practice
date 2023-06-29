// https://leetcode.com/problems/diagonal-traverse

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& v) {
        vector<int> res;
        map<int,vector<int>> mp;

        int n=v.size(), m=v[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[i+j].push_back(v[i][j]);
            }
        }

        for(auto [key, u]: mp)
        {
            if(key%2==0) reverse(u.begin(),u.end());

            for(auto it: u) res.push_back(it);
        }

        return res;
    }
};
