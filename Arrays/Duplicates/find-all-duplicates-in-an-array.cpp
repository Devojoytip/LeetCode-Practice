// https://leetcode.com/problems/find-all-duplicates-in-an-array
/*
Same approach as finding missing elements

Since range [1-N] so we iterate over the arr
Use idx = v[i]-1 as index and mark the value in v[idx] -ve
If already -ve means we visited it earlier ie has duplicates as for each x in [1,N] we will reach v[x-1] once only if no duplicates

*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& v) {

        vector<int> res;
        
        for(int i=0;i<v.size();i++)
        {
            int num=abs(v[i]);
            if(v[num-1]>0) v[num-1]*=-1;
            else res.push_back(num);
        }
        
        return res;
    }
};
