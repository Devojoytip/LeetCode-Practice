/*

https://leetcode.com/problems/minesweeper

*/

class Solution {
public: 
    vector<pair<int,int>> dir{{1,-1},{1,0},{1,1},{-1,-1},{-1,0},{-1,1},{ 0,-1 },{ 0,1}};
    void dfs(vector<vector<char>>& u,int x,int y,bool &flag)
    {
        if(x<0 or y<0 or x>=u.size() or y>=u[0].size() or flag) return;
        char curr=u[x][y];
        if(curr=='M') 
        {
            u[x][y]='X';
            flag=1;
            return;
        }

        if(curr=='E') 
        {
            int cnt=0;
            for(auto [dx,dy]: dir)
            {
                int newX=x+dx,newY=y+dy;
                if(newX>=0 and newY>=0 and newX<u.size() and newY<u[0].size() and u[newX][newY]=='M') cnt++;
            }

            if(cnt) u[x][y]=cnt + '0';

            else
            {
                u[x][y]='B';
                for(auto [dx,dy] : dir)
                {
                    int newX=x+dx,newY=y+dy;
                    dfs(u,newX,newY,flag);
                }
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& v, vector<int>& click) {
        int x=click[0],y=click[1];
        vector<vector<char>> u=v;
        bool flag=0;
        dfs(u,x,y,flag);

        return u;
    }
};
