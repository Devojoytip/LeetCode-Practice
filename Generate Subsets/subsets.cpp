// https://leetcode.com/problems/subsets/description/

// Take & Not take
class Solution {
public:
    vector<vector<int>> res;
    void sol(vector<vector<int>> &res,vector<int>& v,vector<int> curr,int idx,int n)
    {
        if(idx==n)
        {
            res.push_back(curr);
            return;
        }
        
        sol(res,v,curr,idx+1,n);
        curr.push_back(v[idx]);
        sol(res,v,curr,idx+1,n);
    }
    vector<vector<int>> subsets(vector<int>& v) {
        int n=v.size();
        vector<int> curr;
        sol(res,v,curr,0,n);
        return res;
    }
};
