/*

https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix

Row-wise binary search 

*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& v) {
        
        int rows(v.size()),cols(v[0].size()),cnt(0);

        for(int i=0;i<rows;i++)
        {
            if(v[i][0]<0) cnt+=cols;
            else
            {
                int s=0,e=cols-1;

                while(s<=e)
                {
                    int mid=s+(e-s)/2;
                    if(v[i][mid]<0) 
                    {
                        cnt+=e-mid+1;
                        e=mid-1;
                    }
                    else s=mid+1;
                }
            }
        }

        return cnt;
    }
};
