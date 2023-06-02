/*
https://leetcode.com/problems/detonate-the-maximum-bombs

DIFF: This is an unidirected graph ie ith bomb can detonate jth bomb but doen't neab jth bomb can also detonate ith bomb
So if we go on jth bomb and mark as present in dfs, after dfs we need to mark i absent so ith bomb can call dfs on it

1. create adjacency matrix by iterating over all points & check their distance< r1+r2 -> O(N^2)
2. call dfs on every node which further calls dfs on its neigh
3. count the vis nodes after dfs call on each node

*/

class Solution {
public:

    #define ll long long
    void dfs(int src,vector<int>& vis,vector<int> adj[]){
        vis[src]=1;
        for(int x:adj[src]){
            if(vis[x]==0){
                dfs(x,vis,adj);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        
          int n=bombs.size();
          vector<int> adj[n];

        for(int i=0;i<n;i++){

            ll r1=bombs[i][2];
            ll x1=bombs[i][0];
            ll y1=bombs[i][1];

            for(int j=0;j<n;j++){

                if(i!=j){

                    ll x2=bombs[j][0];
                    ll y2=bombs[j][1];
                    ll r2=bombs[j][2];
                    ll dsq=(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);;
                    if(dsq<=r1*r1){
                        adj[i].push_back(j); 
                    }
                }
            }
        }

        vector<int> vis(n);
        int ans=0;

        for(int i=0;i<n;i++){

            dfs(i,vis,adj); 
            int cnt=0;

            for(int j=0;j<n;j++) 
              if(vis[j]==1) cnt++;

            ans=max(ans,cnt);
            fill(vis.begin(),vis.end(),0);
        }

        return ans;
    }
};
