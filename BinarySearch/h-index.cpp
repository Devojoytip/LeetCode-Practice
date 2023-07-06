// https://leetcode.com/problems/h-index

class Solution {
public:
    int hIndex(vector<int>& v) {

        sort(v.begin(),v.end());

        int n=v.size(), s=0, e=n-1;

        while(s<=e)
        {
            int m=(s+e)/2;

            if(v[m] == n-m) return v[m];

            else if(v[m]<n-m) s=m+1;

            else e=m-1;
        }

        return n-s;
    }
};
