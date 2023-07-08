// 

class Solution {
public:
    void recur(vector<int>& v,vector<vector<int>> &res,vector<int> curr, int idx, int sum) 
    {
        if(sum==0)
        {
            res.push_back(curr);
            return;
        }
        
        if(idx>=v.size() or sum<0) return;

        for(int i=idx;i<v.size();i++)
        {
            curr.push_back(v[i]);
            recur(v,res,curr,i,sum-v[i]);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& v, int sum) {
        
        vector<vector<int>> res;
        vector<int> curr;

        recur(v,res,curr,0,sum);

        return res;
    }
};
