// https://leetcode.com/problems/combinations

class Solution {
public:
    void recur(vector<vector<int>> &res,vector<int> curr,int n,int idx,int k)
    {
        if(curr.size()==k)
        {
            res.push_back(curr);
            return;
        }

        for(int i=idx;i<=n;i++)
        {
            curr.push_back(i);   
            recur(res,curr,n,i+1,k);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>>res;
        vector<int>curr;
        recur(res,curr,n,1,k);
        return res;    
    }
};
