// https://leetcode.com/problems/combination-sum

class Solution {
public:
    void f(vector<int>& v, vector<int> curr, vector<vector<int>> &res, int i, int t) {
        
        if(t==0)
        {
            res.push_back(curr);
            return;
        }

        if(i==v.size() or t<0) return;

        f(v,curr,res,i+1,t);

        curr.push_back(v[i]);
        f(v,curr,res,i,t-v[i]);
    }

    vector<vector<int>> combinationSum(vector<int>& v, int t) {
        
        vector<vector<int>> res;
        f(v,{},res,0,t);

        return res;
    }
};
