// https://leetcode.com/problems/subarray-product-less-than-k/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& v, int k) {
        
        int i=0, j=0, ans=0, prod=1, n=v.size();
        
        while(j<n)
        {
            prod*=v[j];
            while(i<=j and prod>=k)
            {
                prod/=v[i];
                i++;
            }
            ans += j-i+1;
            j++;
        }

       return ans; 
    }
};
