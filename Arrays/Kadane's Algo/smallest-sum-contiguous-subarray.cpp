// https://practice.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// KADANE'S ALGO
class Solution{
  public:
  int smallestSumSubarray(vector<int>& v){
      //Code here
      int ans=1e9, sum=0, n=v.size();
      
      for(int i=0;i<n;i++)
      {
          sum+=v[i];
          ans=min(ans, sum);
          if(sum>0) sum=0;
      }
      
      return ans;
  }
};
