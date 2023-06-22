// https://leetcode.com/problems/island-perimeter

class Solution {
public:
void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>& grid,int& peri){
        vis[row][col]=1;
        int a=0;
        int drow[4]={1,-1,0,0};
        int dcol[4]={0,0,1,-1};
        for(int i=0;i<4;i++)
        {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 and ncol>=0 and nrow<grid.size() and ncol<grid[0].size() and grid[nrow][ncol]==1) a++;
            if(nrow>=0 and ncol>=0 and nrow<grid.size() and ncol<grid[0].size() and grid[nrow][ncol]==1 and vis[nrow][ncol]==0 ) dfs(nrow,ncol,vis,grid,peri);
        }
        peri+=4-a;
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int peri=0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(!vis[i][j] and grid[i][j]==1) dfs(i,j,vis,grid,peri);
            }
        }
        return peri;
    }
};
