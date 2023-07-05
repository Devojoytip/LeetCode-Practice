// https://leetcode.com/problems/battleships-in-a-board

class Solution {
    
    vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
    
    void dfs(int i,int j,vector<vector<char>>& v)
    {
        
        if(i<0 or i>=v.size() or j<0 or j>=v[0].size() or v[i][j] == '.') return;
                 
        v[i][j] = '.';  // to mark visited

        for(auto [dx, dy] : dir) dfs(i+dx,j+dy,v);
    }

public:

    int countBattleships(vector<vector<char>>& v) 
    {
        int ans=0;
        
        for(int i=0 ; i<v.size() ; i++)
        {
            for(int j=0 ; j<v[0].size() ; j++)
            {
                if(v[i][j] == 'X') // after dfs the entire connected comp. is marked .
                {
                    dfs(i,j,v);
                    ans++; // as we need to find no of components
                }
            }
        }

        return ans;
    }
};
