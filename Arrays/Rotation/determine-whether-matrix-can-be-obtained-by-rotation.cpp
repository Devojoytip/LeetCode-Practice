// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation

class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        
        int n(v.size());

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++) swap(v[i][j],v[j][i]);
        }

        for(auto &it: v) reverse(it.begin(),it.end());
    }

    bool findRotation(vector<vector<int>>& v, vector<vector<int>>& u) {
        
        if(v==u) return 1;

        for(int i=0;i<3;i++) // 90 deg, 180 deg, 270 deg
        {
            rotate(v);
            if(v==u) return 1;
        }

        return 0;
    }
};
