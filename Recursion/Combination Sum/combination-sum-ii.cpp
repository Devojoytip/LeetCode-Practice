// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    void f(vector<int>& v, vector<int> curr, vector<vector<int>>& res, int i, int t) {
        
        if(t==0)
        {
            res.push_back(curr);
            return;
        }

        if(i==v.size() or t<0) return;

        curr.push_back(v[i]);
        f(v,curr,res,i+1,t-v[i]);
        curr.pop_back();

        i=upper_bound(v.begin(),v.end(),v[i])-v.begin();
        f(v,curr,res,i,t);
    }

    vector<vector<int>> combinationSum2(vector<int>& v, int t) {

        vector<vector<int>> res;
        sort(v.begin(),v.end());
        f(v,{},res,0,t);

        return res;    
    }
};
