// https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int row=v.size()-1,col=v[0].size()-1;
        int i=0,j=col;

        while(i<=row and j>=0)
        {
            if(v[i][j]==t) return 1;
            else if(v[i][j]>t) j--;
            else  i++;
        }

        return 0;
    }
};
