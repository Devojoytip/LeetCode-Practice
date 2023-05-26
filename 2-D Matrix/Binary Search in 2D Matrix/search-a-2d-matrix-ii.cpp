// https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int i=0;
        int rows=v.size()-1,cols=v[0].size()-1;

        for(int i=0;i<v.size();i++)
        {
            if(v[i][0]<= t and v[i][cols]>= t)
            {
                int s=0,e=cols;
                int mid=(s+e)/2;
                while(s<=e)
                {
                    mid=(s+e)/2;
                    if(v[i][mid]==t) return 1;
                    else if(v[i][mid]>t) e--;
                    else s++;
                }
            }

        }

        return 0;
    }
};
