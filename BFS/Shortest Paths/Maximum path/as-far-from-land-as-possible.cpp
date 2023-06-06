// https://leetcode.com/problems/as-far-from-land-as-possible

class Solution {
public:
    int maxDistance(vector<vector<int>>& v) {
        
        int n=v.size();
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==1) q.push({i,j});
            }
        }

        vector<vector<bool>> vis(n,vector<bool>(n,0));
        vector<pair<int,int>> dir ={{0,1},{1,0},{0,-1},{-1,0}};
        int ans=-1;
        bool flag=0;

        while(!q.empty())
        {
            int len=q.size();
            ans++;
            while(len--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                vis[x][y]=1;
                for(auto [dx,dy]: dir)
                {
                    int X=x+dx,Y=y+dy;
                    if(X>=0 and Y>=0 and X<n and Y<n and !vis[X][Y] and v[X][Y]==0)
                    {
                        flag=1;
                        vis[X][Y]=1;
                        q.push({X,Y});
                    }
                }
            }
        }

        return (flag) ? ans : -1;
    }
};
