// https://leetcode.com/problems/max-consecutive-ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& v) {
        
        int i=0,j=0,ans=0;

        while(j<v.size())
        {
            if(v[j]==1) 
            {
                ans=max(ans,j-i+1);
                j++;
                continue;
            }
            while(j<v.size() and v[j]!=1)
            {
                j++;
            }
            i=j;
        }

        return ans;
    }
};
