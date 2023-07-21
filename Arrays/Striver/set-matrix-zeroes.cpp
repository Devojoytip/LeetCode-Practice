// https://leetcode.com/problems/set-matrix-zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        int col0=1,m=v.size(),n=v[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==0)
                {
                    v[i][0]=0;
                    if(j!=0) v[0][j]=0;
                    else col0=0;
                }
            }
        }

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(v[i][j]!=0)
                {
                    if(v[0][j] == 0 or v[i][0] == 0) v[i][j]=0;
                }
            }
        }

        if(v[0][0]==0)
        {
            for(int j=0;j<n;j++) v[0][j] = 0;
        }

        if(col0 == 0)
        {
            for(int i=0;i<m;i++) v[i][0] = 0;
        }
    }
};
