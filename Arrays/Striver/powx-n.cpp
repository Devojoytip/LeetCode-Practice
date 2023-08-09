// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
        
        if(x==1 or n==0) return 1.0;

        while(n%2==0)
        {
            x*=x;
            n/=2;
        }

        return (n>0) ? x*myPow(x,n-1) : 1/myPow(x,-n);
    }
};
