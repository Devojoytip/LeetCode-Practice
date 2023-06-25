// https://leetcode.com/problems/longest-harmonious-subsequence

class Solution {
public:
    int findLHS(vector<int>& v) {
        sort(v.begin(),v.end());
        int i=0,j=0,ans=0;

        while(j<v.size())
        {
            if(v[j]-v[i]==1)
            {
                ans=max(ans,j-i+1);
            }
            else
            {
                while(v[j]-v[i]>1) i++;
            }
            j++;
        }

        return ans;
    }
};
