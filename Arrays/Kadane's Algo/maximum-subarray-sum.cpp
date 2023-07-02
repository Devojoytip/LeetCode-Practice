// https://leetcode.com/problems/maximum-subarray
// Kadane's Algo

class Solution {
public:
    int maxSubArray(vector<int>& v) {

      int n=v.size(),maxi=INT_MIN,sum=0;

      for(int i=0;i<n;i++)
      {
        sum+=v[i];
        maxi=max(sum,maxi);
        if(sum<0) sum=0;
      }

      return maxi;
    }
};
