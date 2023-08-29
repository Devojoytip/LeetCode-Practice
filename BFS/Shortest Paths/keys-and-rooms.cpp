// https://leetcode.com/problems/keys-and-rooms

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& v) 
    {
        int n=v.size(), cnt=0;

        unordered_map<int, bool> vis;
        for(int i=0;i<n;i++) vis[i]=0;

        queue<int> q;
        q.push(0);
        vis[0]=1;

        while(q.size())
        {
            int i=q.front();
            q.pop();
            cnt++;
            if(i<n)
            {
                for(auto it: v[i]) 
                {
                    if(vis[it]==0) 
                    {
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
        
        return cnt==n;
    }
};
