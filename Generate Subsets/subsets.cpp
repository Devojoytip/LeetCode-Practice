// https://leetcode.com/problems/subsets/description/

class Solution {
public:
    vector<vector<int>> v;
    void sol(vector<int>& a,vector<int> b,int i,int j,int n)
    {
        if(i==n)
        {
            vector<int>c;
            for(int k=0;k<j;k++) c.push_back(b[k]);
            v.push_back(c);
            return;
        }
        b[j]=a[i];
        sol(a,b,i+1,j+1,n);
        sol(a,b,i+1,j,n);
    }
    vector<vector<int>> subsets(vector<int>& a) {
        int n=a.size();
        vector<int> b(n);
        sol(a,b,0,0,n);
        return v;
    }
};
