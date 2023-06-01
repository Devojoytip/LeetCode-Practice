/*

https://leetcode.com/problems/count-sub-islands

*/

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int ans = 0;
        
        for(int i=0; i<grid1.size(); i++)
        {
            for(int j=0; j<grid1[i].size(); j++)
            {
                if(grid2[i][j] == 1 and grid2[i][j] == grid1[i][j])
                {
                    bool flag=1;
                    dfs(grid1, grid2, i, j, flag);
                    if(flag) ans++;
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j,bool &flag)
    {
        if(i<0 or j<0 or i>=grid1.size() or j>=grid1[0].size() or grid2[i][j]==0) return; 
        
        if(grid2[i][j] != grid1[i][j]) 
        {
            flag=0;
            return;
        }

        grid2[i][j]=0;

        dfs(grid1, grid2, i+1, j, flag);
        dfs(grid1, grid2, i-1, j, flag);
        dfs(grid1, grid2, i, j+1, flag);
        dfs(grid1, grid2, i, j-1, flag);
        
    }
};
