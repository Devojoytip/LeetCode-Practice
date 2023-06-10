// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        
        int i=0,j=0,cnt=0,ans=0;

        while(j<v.size())
        {
            if(v[j]==1) 
            {
                ans=max(ans,j-i+1);
                j++;
            }
            else
            {
                if(cnt==k)
                {
                    while(i<=j and v[i]!=0) i++;
                    if(v[i]==0) 
                    {
                        i++;
                        cnt--;
                    }
                    else 
                    {
                        j++;
                        cnt=0;
                    }
                }
                if(cnt<k)
                {
                    ans=max(ans,j-i+1);
                    j++;
                    cnt++;
                }
            }
        }
        ans=max(ans,j-i);
        return ans;
    }
};
