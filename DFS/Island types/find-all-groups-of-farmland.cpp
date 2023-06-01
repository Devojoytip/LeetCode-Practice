/*

https://leetcode.com/problems/find-all-groups-of-farmland

  1. iterate over all points
  2. if it is 1 -> save its i,j as top left corner and i,j as bottom right corner and call dfs on it
  3. as it calls dfs on its neigh update values of bottom right if its i,j increases as bottom right has highest value
  
*/


class Solution {
public:

    void dfs(vector<vector<int>>& v,vector<int> &curr,int i,int j)
    {
        if(i<0 or j<0 or i>=v.size() or j>=v[0].size() or v[i][j]==0) return;

        v[i][j]=0;

        if(i>curr[2])
        {
            curr[2]=i;
            curr[3]=j;
        }
        else if(i==curr[2] and j>curr[3]) curr[3]=j;

        dfs(v,curr,i+1,j);
        dfs(v,curr,i-1,j);
        dfs(v,curr,i,j+1);
        dfs(v,curr,i,j-1);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& v) {

        vector<vector<int>> res;

        for(int i=0;i<v.size();i++){
            for(int j = 0;j<v[0].size();j++){
                if(v[i][j]){
                    vector<int> curr = {i,j,i,j};
                    dfs(v,curr,i,j);
                    res.push_back(curr);
                }
            }
        }

        return res;
    }
};
