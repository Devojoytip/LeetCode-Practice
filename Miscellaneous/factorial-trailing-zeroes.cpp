// https://leetcode.com/problems/factorial-trailing-zeroes

class Solution {
public:

    // TO COUNT NUMBER OF TRAILING ZERO WE USE FOLLOWING FORMULA..
    //(N/5^1)+(N/5^2)+(N/5^3)......     WHERE(N/5^p) >=1

    // OR TC - O(log n)
    
    int trailingZeroes(int n) 
    {
        int count=0;
        while (n>0)
        {
            count += n/5;
            n = n/5;
        }
        return count;
    }
};
