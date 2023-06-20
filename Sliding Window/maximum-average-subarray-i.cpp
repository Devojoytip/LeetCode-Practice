// https://leetcode.com/problems/maximum-average-subarray-i 

class Solution {
public:
    double findMaxAverage(vector<int>& v, int k) {
        int i=0,j=0;
        double sum=0,ans=INT_MIN;

        while(j<v.size())
        {
            sum+=v[j];
            if(j-i+1<k) j++;
            else
            {
                ans=max(ans,sum);
                sum-=v[i];
                i++;
                j++;
            }
        }

        return ans/k;
    }
};
