// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    vector<vector<int>> res;
    void sol(vector<vector<int>> &res,vector<int>& v,vector<int> curr,int idx,int n)
    {
        if(idx>=n)
        {
            res.push_back(curr);
            return;
        }

        curr.push_back(v[idx]);
        sol(res,v,curr,idx+1,n);
        curr.pop_back();
        
        while(v.size()>idx+1 and v[idx+1]==v[idx]) idx++; // ignore all duplicates
        sol(res,v,curr,idx+1,n);   

    }

    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        int n=v.size();
        vector<int> curr;
        sort(v.begin(),v.end());
        sol(res,v,curr,0,n);
        return res;
    }
};
