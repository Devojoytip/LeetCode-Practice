// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        
        int prefix_sum=1,suffix_sum=1;
        vector<int> res(v.size(),1);

        for(int i=0;i<v.size();i++)
        {
            res[i]=prefix_sum;
            prefix_sum*=v[i];
        }

        for(int i=v.size()-1;i>=0;i--)
        {
            res[i]*=suffix_sum;
            suffix_sum*=v[i];
        }

        return res;
    }
};
