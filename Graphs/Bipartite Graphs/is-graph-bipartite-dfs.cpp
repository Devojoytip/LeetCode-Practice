// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    bool dfs(int curr, vector<vector<int>>& v, vector<int> &col, int color)
    {
        if(col[curr]!=-1 and col[curr]!=color) return 0;

        if(col[curr]==color) return 1;

        col[curr]=color;

        color = (color==0) ? 1 : 0;

        for(auto adj: v[curr])
        {
            if(!dfs(adj,v,col,color)) return 0;
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
                if(!dfs(i,v,col,1)) return 0;
            }
        }

        return 1;
    }
};
