// https://leetcode.com/problems/unique-paths-iii

class Solution {
   
   public:
   
     int dfs(vector<vector<int>>& v,vector<vector<vector<int>>> &dp,int x,int y,int z,int m,int n,int cnt){
       if(x< 0 or y<0 or y>=v[0].size() or x >= v.size() or v[x][y]==-1 ) return 0;
       
       if(v[x][y]==2) return z == cnt ? 1 : 0;

       if(dp[x][y][z]!=-1) return dp[x][y][z];
        
        v[x][y]=-1;
       
       int up=dfs(v,dp,x,y-1,z+1,m,n,cnt);
       int down=dfs(v,dp,x,y+1,z+1,m,n,cnt);
       int left=dfs(v,dp,x-1,y,z+1,m,n,cnt);
       int right=dfs(v,dp,x+1,y,z+1,m,n,cnt);
       int ans=up+down+left+right;
       //backtracking 
       v[x][y]=0;
       
       return dp[x][y][z+1]=ans;
    }

    int uniquePathsIII(vector<vector<int>>& v) {
        int cnt=1,x=0,y=0,m=v.size(),n=v[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(v[i][j]==0) cnt++;
                else if(v[i][j]==1){
                    x=i;
                    y=j;
                }
            }
        }
        
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(cnt+1,-1)));
        return dfs(v,dp,x,y,0,m,n,cnt);
    }
};
