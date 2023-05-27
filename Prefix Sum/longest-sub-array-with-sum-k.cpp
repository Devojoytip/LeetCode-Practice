// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

class Solution {
public:
    int lenOfLongSubarr(int arr[],  int n, int k) {
        map<int,int> mp;
        int ans=0,sum=0;

        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum==k) ans=max(ans,i+1);

            else
            {
                int rem=sum-k;
                if(mp.find(rem)!=mp.end())
                {
                    ans=max(ans,i-mp[rem]);
                }
            }
            
            if(mp.find(sum)==mp.end()) mp[sum]=i;
        }

        return ans;
    }
};
