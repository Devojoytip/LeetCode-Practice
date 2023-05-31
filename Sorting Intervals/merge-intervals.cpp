/*

https://leetcode.com/problems/merge-intervals/description/

O(n logn)

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>> u=v;
        sort(u.begin(),u.end());
        vector<vector<int>> res;

        for(auto it:u)
        {
            if(res.empty() or res.back()[1]<it[0]) res.push_back(it);
            else res.back()[1] = max(res.back()[1],it[1]);
        }

        return res;
    }
};
