// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        
        int n=v.size(), s=0, e=n-1;

        if(n==1) return v[s];
        if(v[s+1]!=v[s]) return v[s];
        if(v[n-1]!=v[n-2]) return v[n-1];

        s=1, e=n-2;

        while(s<=e)
        {
            int mid=(s+e)/2;

            if(v[mid]!=v[mid-1] and v[mid]!=v[mid+1]) return v[mid];

            else if((mid%2==0 and v[mid+1]==v[mid]) or (mid%2==1 and v[mid-1]==v[mid])) s=mid+1;

            else e=mid-1;
        }

        return -1;
    }
};
