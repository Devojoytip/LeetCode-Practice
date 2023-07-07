// https://leetcode.com/problems/permutations/

class Solution {
public:
    void recur(vector<int> &v, vector<vector<int>> &res, vector<int> curr, vector<int>& vis, int cnt) 
    {
        if(cnt==v.size()) 
        {
            res.push_back(curr);
            return;
        }

        for(int i=0;i<v.size();i++)
        {
            if(vis[i]) continue;

            vis[i]=1;
            curr.push_back(v[i]);

            recur(v,res,curr,vis,cnt+1);
            
            // Back-tracking
            vis[i]=0;
            curr.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& v) {
        
        vector<vector<int>> res;
        
        vector<int> vis(v.size(),0);

        recur(v,res,{},vis,0);

        return res;
    }
};
