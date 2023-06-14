// https://leetcode.com/problems/count-the-number-of-fair-pairs

class Solution {
public:
    long long countFairPairs(vector<int>& v, int lower, int upper) {
        
        sort(v.begin(),v.end());
        
        long long ans=0;

        for(int i=0;i<v.size();i++)
        {
            int x=lower_bound(v.begin()+i+1,v.end(),lower-v[i])-v.begin()+i;
            int y=upper_bound(v.begin()+i+1,v.end(),upper-v[i])-v.begin()+i;
            ans+=y-1-x+1;
        }

        return ans;
    }
};
