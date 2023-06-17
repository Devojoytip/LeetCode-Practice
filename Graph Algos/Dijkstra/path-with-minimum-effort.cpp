// https://leetcode.com/problems/path-with-minimum-effort

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& v) {

        int n=v.size(),m=v[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
 
        pq.push({0,{0,0}});
        dist[0][0]=0;

        vector<pair<int,int>> d{{0,1},{0,-1},{1,0},{-1,0}};

        while(!pq.empty())
        {
            auto [effort,point]=pq.top();
            auto [x,y]=point;
            pq.pop();

            if(x==n-1 and y==m-1) return effort;

            for(auto [dx,dy] : d)
            {
                int newX=x+dx;
                int newY=y+dy;

                if(newX>=0 and newY>=0 and newX<n and newY<m)
                {
                    int newEffort=max(effort,abs(v[x][y]-v[newX][newY]));
                    if(dist[newX][newY]>newEffort)
                    {
                        dist[newX][newY]=newEffort;
                        pq.push({dist[newX][newY],{newX,newY}});
                    }
                }
            }
        }

        return -1;
    }
};
