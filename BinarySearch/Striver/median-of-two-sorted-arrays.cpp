// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        
        int n=a.size(), m=b.size();
        
        if(m < n) return findMedianSortedArrays(b,a);
        
        int s=0, e=n;

        while(s<=e)
        {
            int c1=(s+e)/2;
            int c2=(n+m+1)/2-c1;

            int l1=(c1==0)?INT_MIN:a[c1-1];
            int l2=(c2==0)?INT_MIN:b[c2-1];
            int r1=(c1==n)?INT_MAX:a[c1];
            int r2=(c2==m)?INT_MAX:b[c2];

            if(l1<=r2 and l2<=r1)
            {
                if((n+m)%2==0) return (max(l1,l2)+min(r1,r2))/2.0;
                return max(l1,l2);
            }

            else if(l1>r2) e=c1-1;

            else s=c1+1;
        }

        return 0.0;
    }
};
