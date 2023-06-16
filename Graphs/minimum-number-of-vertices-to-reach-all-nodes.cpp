// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& e) {
        vector<int> res;
        vector<int> vis(n,0);

        for(auto it:e) vis[it[1]]=1;

        for(int i=0;i<n;i++)
        {
            if(!vis[i]) res.push_back(i);
        }

        return res;
    }
};
