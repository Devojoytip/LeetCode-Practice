// https://leetcode.com/problems/next-permutation
// https://www.youtube.com/watch?v=LuLCLgMElus

class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int n=v.size(),idx=-1;

        for(int i=n-2;i>=0;i--)
        {
            if(v[i+1]>v[i]) 
            {
                idx=i;
                break;
            }
        }

        for(int i=n-1;i>=0 and idx!=-1;i--)
        {
            if(v[i]>v[idx]) 
            {
                swap(v[i],v[idx]);
                break;
            }
        }

        reverse(v.begin()+idx+1,v.end());

    }
};
