// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int a[], int n)
    {
      //Your code here
      
      int ans=1;
      
      unordered_map<int,int> mp;
      
      for(int i=0;i<n;i++) mp[a[i]]=1;
      
      for(int i=0;i<n;i++)
      {
          if(mp.find(a[i]-1)==mp.end())
          {
              int curr=a[i]+1;
              
              while(mp.find(curr)!=mp.end())
              {
                  curr++;
                  mp[a[i]]++;
              }
          }
      }
      
      for(auto it: mp) ans=max(ans,it.second);
      
      return ans;
    }
};
