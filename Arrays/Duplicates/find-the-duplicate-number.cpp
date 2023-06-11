// https://leetcode.com/problems/find-the-duplicate-number

// Binary Search

class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int n=a.size()-1;
        
        int s=1,e=n,ans=-1;
        
        while(s<=e)
        {
            int mid=s+(e-s)/2,cnt=0;
            
            for(int i:a)
            {
                if(i<=mid) cnt++;
            }
            if(cnt>mid) {
                e=mid-1;
                ans=mid;
            }
            else s=mid+1;
        }
        
        return ans;
    }
};
