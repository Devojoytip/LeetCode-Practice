/*

RECURSIVE :

To check if n is power of k

https://leetcode.com/problems/power-of-four
https://leetcode.com/problems/power-of-three

*/

class Solution {
public:
    bool isPowerOfK(int n,int k) {
        if(n<1) return 0;
        if(n==1) return 1;
        return (n%k==0) and isPowerOfK(n/k);
    }
};
