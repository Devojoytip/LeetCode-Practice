/*
  
  https://leetcode.com/problems/shortest-path-in-binary-matrix/
  
  check if start and end points are valid or not ie can be visited or not
  init cost of start point as 1
  for shortest path we need to update the cost of every node's every valid neighbour we visit by 1 when visited for first time
  return cost of end point
  
*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& v) {
        queue<pair<int,int>> q;
        int i=0,j=0,ans=0;
        int m = v.size();
        int n = v[0].size();

        q.push({i,j});
        vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
        if(v[i][j]==1 or v[m-1][n-1]==1) return -1;

        v[i][j]=1;

        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            ans++;
            if(x==m-1 and y==n-1) return v[m-1][n-1];

            for(auto [dx,dy]:dir)
            {
                int X=x+dx;
                int Y=y+dy;
                if(X>=0 and Y>=0 and X<m and Y<n and v[X][Y]==0)
                {
                    q.push({X,Y});
                    v[X][Y]=v[x][y]+1;
                }
            }
        }

        return -1;
    }
};
