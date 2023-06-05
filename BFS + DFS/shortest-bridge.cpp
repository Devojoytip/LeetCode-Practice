/*

https://leetcode.com/problems/shortest-bridge

*/

class Solution {
public:

    void dfs(vector<vector<int>>& v,queue<pair<int,int>> &q,int i,int j) {

        if(i<0 or j<0 or i>=v.size() or j>=v[0].size() or v[i][j]==0 or v[i][j]==2) return;

        v[i][j]=2;
        q.push({i,j});

        dfs(v,q,i+1,j);
        dfs(v,q,i-1,j);
        dfs(v,q,i,j+1);
        dfs(v,q,i,j-1);
    }

    int bfs(vector<vector<int>>& v,queue<pair<int,int>> q) {
        int ans=1e9,curr_dis=0;
        vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        while(!q.empty())
        {
            int n = q.size();

            while(n--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();

                for(auto [dx,dy]: dir)
                {
                    int X=x+dx;
                    int Y=y+dy;

                    if(X>=0 and Y>=0 and X<v.size() and Y<v[0].size() and v[X][Y]!=2) 
                    {
                        if(v[X][Y]==1) ans=min(ans,curr_dis);
                        else
                        {
                            q.push({X,Y});
                            v[X][Y] = 2;
                        }                   
                    }
                }
            }
            curr_dis++;
        }

        return ans;
        
    }

    int shortestBridge(vector<vector<int>>& v) {

        queue<pair<int,int>> q;
        bool flag=0;

        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[0].size();j++)
            {
                if(v[i][j]==1) 
                {
                    dfs(v,q,i,j);
                    q.push({i,j});
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }

        return bfs(v,q);
    }
};
