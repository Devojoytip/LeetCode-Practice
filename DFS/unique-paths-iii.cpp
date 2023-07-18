// https://leetcode.com/problems/unique-paths-iii

class Solution {
public:

    void dfs(vector<vector<int>>& v, vector<vector<int>>& vis, int &cnt, int sq, int i, int j, int n, int m) 
    {
        if(i<0 or j<0 or i>=n or j>=m or v[i][j]==-1 or vis[i][j]) return;

        if(v[i][j]==2) 
        {
            if(sq==0) cnt++;
            return;
        }

        vis[i][j]=1;
        if(v[i][j]==0) sq--;

        dfs(v,vis,cnt,sq,i+1,j,n,m);
        dfs(v,vis,cnt,sq,i,j+1,n,m);
        dfs(v,vis,cnt,sq,i-1,j,n,m);
        dfs(v,vis,cnt,sq,i,j-1,n,m);

        vis[i][j]=0;
        sq++;
    }

    int uniquePathsIII(vector<vector<int>>& v) {
        
        int n=v.size(), m=v[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt=0, sq=0, x, y;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==1) x=i,y=j;
                if(v[i][j]==0) sq++;
            }
        }
        
        dfs(v,vis,cnt,sq,x,y,n,m);

        return cnt;
    }
};
