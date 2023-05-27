// https://leetcode.com/problems/minimum-size-subarray-sum/
// Aditya Verma Approach

class Solution {
public:
    int minSubArrayLen(int t, vector<int>& v) {
        int i=0,j=0,sum=0,ans=INT_MAX;

        while(j<v.size())
        {
            sum+=v[j];

            if(sum<t) j++;

            else if(sum==t)
            {
                ans=min(ans,j-i+1);
                j++;
            }

            else if(sum>t)
            {
                while(sum>=t)
                {
                    ans=min(ans,j-i+1);
                    sum-=v[i];
                    i++;
                }
                j++;
            }
        }

        return (ans==INT_MAX) ? 0 : ans;
    }
};
