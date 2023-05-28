// https://leetcode.com/problems/word-search/

class Solution {
public:
    bool dfs(vector<vector<char>>& v,int x,int y,string s,int idx,vector<vector<bool>> &vis)
    {
        if(idx==s.size()) return 1;
        if(x<0 or y<0 or x>=v.size() or y>=v[0].size() or v[x][y]!=s[idx] or vis[x][y]) return 0;
        vis[x][y]=1;
        idx++;
        bool right = dfs(v,x+1,y,s,idx,vis);
        if(right) return 1;
        bool left = dfs(v,x-1,y,s,idx,vis);
        if(left) return 1;
        bool down = dfs(v,x,y+1,s,idx,vis);
        if(down) return 1;
        bool up = dfs(v,x,y-1,s,idx,vis);
        if(up) return 1;
        vis[x][y]=0;
        return 0;
    }

    bool exist(vector<vector<char>>& v, string s){
        vector<vector<bool>> vis(v.size(),vector<bool>(v[0].size(),0));
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[0].size();j++)
            {
                if(dfs(v,i,j,s,0,vis)) return 1;
            }
        }
        return 0;
    }
};
