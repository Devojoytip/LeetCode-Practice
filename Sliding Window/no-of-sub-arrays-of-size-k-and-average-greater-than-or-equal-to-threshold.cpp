// https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold

class Solution {
public:
    int numOfSubarrays(vector<int>& v, int k, int threshold) {
        
        int i=0,j=0;
        int sum=0,ans=0;

        while(j<v.size())
        {
            sum+=v[j];
            if(j-i+1<k) j++;
            else
            {
                if(sum/k>=threshold) ans++;
                sum-=v[i];
                i++;
                j++;
            }
        }

        return ans;

    }
};
