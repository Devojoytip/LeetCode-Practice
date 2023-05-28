// https://leetcode.com/problems/permutations/

class Solution {
public:
    void recur(vector<vector<int>> &res,vector<int>& v,vector<int> curr,map<int,bool> vis,int idx,int n)
    {
        if(idx==n)
        {
            res.push_back(curr);
            return;
        }

        for(int i=0;i<n;i++)
        {
            int num=v[i];
            if(vis[num]) continue;
            curr.push_back(num);
            vis[num]=1;
            recur(res,v,curr,vis,idx+1,n);
            curr.pop_back();
            vis[num]=0;
        }
    }

    vector<vector<int>> permute(vector<int>& v) 
    {
        vector<vector<int>>res;
        vector<int>curr;
        map<int,bool>vis;
        for(auto it:v) vis[it]=0;
        recur(res,v,curr,vis,0,v.size());
        return res;    
    }
};
