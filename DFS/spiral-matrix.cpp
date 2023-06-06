// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    void dfs(int x,int y,int k,vector<vector<bool>> &vis,vector<pair<int,int>> dir,vector<vector<int>>& v, vector<int> &res)
    {
        if(x<0 or y<0 or x>=v.size() or y>=v[0].size() or vis[x][y]) return;

        vis[x][y]=1;
        res.push_back(v[x][y]);

        int X=x+dir[k].first;
        int Y=y+dir[k].second;
        
        if(X<0 or Y<0 or X>=v.size() or Y>=v[0].size() or vis[X][Y]) 
        {
            k=(k+1)%4;
            dfs(x+dir[k].first,y+dir[k].second,k,vis,dir,v,res);
        }

        dfs(X,Y,k,vis,dir,v,res);
    }
    vector<int> spiralOrder(vector<vector<int>>& v) {
        int m(v.size()),n(v[0].size());

        vector<pair<int,int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        vector<int> res;

        dfs(0,0,0,vis,dir,v,res);

        return res;
    }
};
