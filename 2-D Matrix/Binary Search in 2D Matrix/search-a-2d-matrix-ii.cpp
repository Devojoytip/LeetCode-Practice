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


// 2nd app
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {

        int m=v.size(), n=v[0].size();
        int s=0,e=m*n-1;

        while(s<=e)
        {
            int mid=s+(e-s)/2;
            int ele=v[mid/n][mid%n];
            if(ele==t) return 1;
            else if(ele>t) e--;
            else  s++;
        }

        return 0;
    }
};
