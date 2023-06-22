// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph

// DFS
class Solution {
public:
    vector<int>mp[100001];
    bool vis[100001];
    int cnt;
    
    void dfs(int u)
    {
        vis[u]=1;
        cnt++;
        for(auto &it:mp[u]) 
        {
            if(!vis[it]) dfs(it);
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        
        for(auto &e:edges)
        {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }

        long long ans=(long long)n*(n-1)/2; // total no of pairs
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]) continue;
            cnt=0;
            dfs(i);
            ans -= (long long) cnt*(cnt-1)/2; // subtract reachable pairs
        }

        return ans;
    }
};
