// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();

        int maxLeft=0,maxRight=0,ans=0;
        vector<int> lh(n);
        vector<int> rh(n);

        for(int i=0,j=n-1;i<n and j>=0;i++,j--)
        {
            maxLeft=max(maxLeft,height[i]);
            maxRight=max(maxRight,height[j]);
            lh[i]=maxLeft;
            rh[j]=maxRight;
        }

        for(int i=0;i<n;i++)
        {
            ans+=min(lh[i],rh[i])-height[i];
        }

        return ans;
    }
};
