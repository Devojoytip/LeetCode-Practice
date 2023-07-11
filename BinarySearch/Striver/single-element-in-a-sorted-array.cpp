// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int sol(vector<int>& v) {
        
        int n=v.size();
        
        if(n==1) return v[0];
        
        if(v[0]!=v[1]) return v[0];
        
        if(v[n-1]!=v[n-2]) return v[n-1];

        int s=1,e=n-2;

        while(s<=e)
        {
            int m=(s+e)/2;

            if(v[m]!=v[m-1] and v[m]!=v[m+1]) return v[m];

            if((m%2==0 and v[m+1]==v[m]) or (m%2==1 and v[m-1]==v[m])) s=m+1;

            else e=m-1;
        }

        return -1;
    }

    int singleNonDuplicate(vector<int>& v) {
        return sol(v);    
    }
};
