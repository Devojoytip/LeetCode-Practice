// https://leetcode.com/problems/permutations-ii/

// Use set
class Solution {
public:
    void recur(set<vector<int>> &s,vector<int>& v,vector<int> curr,vector<bool> vis,int cnt,int n)
    {
        if(cnt==n)
        {
            s.insert(curr);
            return;
        }

        for(int i=0;i<n;i++)
        {
            int num=v[i];
            if(vis[i]) continue;
            curr.push_back(num);
            vis[i]=1;
            recur(s,v,curr,vis,cnt+1,n);
            curr.pop_back();
            vis[i]=0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& v) 
    {
        vector<vector<int>>res;
        vector<int>curr;
        vector<bool> vis(v.size(),0);
        set<vector<int>>s;
        recur(s,v,curr,vis,0,v.size());
        for(auto it:s) res.push_back(it);
        return res;    
    }
};
