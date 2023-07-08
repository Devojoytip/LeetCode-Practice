// https://leetcode.com/problems/combination-sum-iii

class Solution {
public:
    void recur(vector<vector<int>> &res, vector<int> curr, int idx, int k, int sum) 
    {
        if(sum==0 and k==0)
        {
            res.push_back(curr);
            return;
        }

        if(idx==10 or k<0) return;

        for(int i=idx;i<10;i++)
        {
            if(i>sum) break;

            curr.push_back(i);
            recur(res,curr,i+1,k-1,sum-i);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int sum) {
        vector<vector<int>> res;
        vector<int> curr;

        recur(res,curr,1,k,sum);

        return res;
    }
};
