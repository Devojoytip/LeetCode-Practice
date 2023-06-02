// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};

    void dfs(vector<vector<int>>& v,vector<vector<bool>>& vis,int x,int y,int &area)
    {
        if(x<0 or y<0 or x>=v.size() or y>=v[0].size() or v[x][y]==0 or vis[x][y]) return;
        vis[x][y]=1;
        area++;

        for(auto [dx,dy] : dir) dfs(v,vis,x+dx,y+dy,area);
    }

    int maxAreaOfIsland(vector<vector<int>>& v) {
        
        vector<vector<bool>> vis(v.size(),vector<bool> (v[0].size(),0));
        int ans=0;

        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[0].size();j++)
            {
                int area=0;
                dfs(v,vis,i,j,area);
                ans=max(ans,area);
            }
        }

        return ans;
    }
};
