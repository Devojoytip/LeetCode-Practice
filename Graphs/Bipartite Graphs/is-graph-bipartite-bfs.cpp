// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:

    bool bfs(int curr, vector<vector<int>>& v, vector<int> &col)
    {
        queue<int>q;
        q.push(curr);
        col[curr]=1;

        while(q.size())
        {
            int i=q.front();
            q.pop();
            int color = (col[i]==0) ? 1 : 0;

            for(auto adj: v[i])
            {
                if(col[adj]==col[i]) return 0;
                else if(col[adj]==-1)
                {
                    q.push(adj);
                    col[adj]=color;
                }
            }
        }

        return 1;
    }

    bool isBipartite(vector<vector<int>>& v) {
        
        int n=v.size();
        vector<int> col(n,-1);

        for(int i=0;i<n;i++)
        {
            if(col[i]==-1) 
            {
                if(!bfs(i,v,col)) return 0;
            }
        }

        return 1;
    }
};
