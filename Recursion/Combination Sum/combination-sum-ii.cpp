// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    void recur(vector<int>& v, vector<vector<int>> &res, vector<int> curr, int idx, int sum) {
        
        if(sum==0)
        {
            res.push_back(curr);
            return;
        }

        if(idx>=v.size()) return;

        for(int i=idx;i<v.size();i++)
        {
            if(v[i]>sum) break;
            
            if(i>idx and v[i]==v[i-1]) continue;

            curr.push_back(v[i]);
            recur(v,res,curr,i+1,sum-v[i]);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& v, int sum) {
        
        sort(v.begin(),v.end());
        
        vector<vector<int>> res;
        
        recur(v,res,{},0,sum);

        return res;
    }
};
