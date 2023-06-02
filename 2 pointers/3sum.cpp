// https://leetcode.com/problems/3sum


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        
        int i=0,n=v.size(),j=n-1;
        vector<vector<int>> dp(n);
        vector<vector<int>> res;

        sort(v.begin(),v.end());

        for(int i=0;i<n-2;i++)
        {
            if(i==0 or (i>0 and v[i]!=v[i-1]))
            {
                int low=i+1,high=n-1,sum=0-v[i];

                while(low<high)
                {
                    if(v[low]+v[high]==sum)
                    {
                        vector<int> u;
                        u.push_back(v[i]);
                        u.push_back(v[low]);
                        u.push_back(v[high]);
                        res.push_back(u);
                        
                        while(low<high and v[low]==v[low+1]) low++;
                        while(low<high and v[high]==v[high-1]) high--;
                        
                        low++;
                        high--;
                    }
                    else if(v[low]+v[high]>sum) high--;
                    else low++;
                }
            }
        }

        return res;
    }
};
