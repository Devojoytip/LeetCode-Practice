// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> v;
        for(int i=0;i<n;i++)
        {
            vector<int> u;
            if(i==0)
            {
                u.push_back(1);
                v.push_back(u);
            }
            else if(i==1)
            {
                u.push_back(1);
                u.push_back(1);
                v.push_back(u);
            }
            else
            {
                u.push_back(1);
                for(int j=0;j<=v[i-1].size()-2;j++)
                {
                    u.push_back(v[i-1][j]+v[i-1][j+1]);
                }
                u.push_back(1);
                v.push_back(u);
            }
        }
        return v;
    }
};
