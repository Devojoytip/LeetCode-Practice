// https://leetcode.com/problems/spiral-matrix-ii

class Solution {
public:
    void dfs(int x,int y,int k,int num,int n,vector<pair<int,int>> dir,vector<vector<int>> &res)
    {
        if(x<0 or y<0 or x>=n or y>=n or res[x][y]!=0 or num>n*n) return;

        res[x][y]=num;

        int X=x+dir[k].first;
        int Y=y+dir[k].second;
        
        if(X<0 or Y<0 or X>=n or Y>=n or res[X][Y]!=0) 
        {
            k=(k+1)%4;
            dfs(x+dir[k].first,y+dir[k].second,k,num+1,n,dir,res);
        }

        dfs(X,Y,k,num+1,n,dir,res);
    }

    vector<vector<int>> generateMatrix(int n) {

        vector<pair<int,int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> res(n,vector<int>(n,0));

        dfs(0,0,0,1,n,dir,res);

        return res;
    }
};
