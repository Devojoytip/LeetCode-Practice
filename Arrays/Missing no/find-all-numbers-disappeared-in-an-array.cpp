/* 
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

Since range [1-N] so we iterate over the arr
Use idx = v[i]-1 as index and mark the value in v[idx] -ve
If already -ve means we visited it earlier ie has duplicates as for each x in [1,N] we will reach v[x-1] once only if no duplicates
after that we iterate again and if v[i] is +ve means we never reached it => we never got i+1 in the arr so push in res

*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& v) {
        
        vector<int> res;

        for(int i=0;i<v.size();i++)
        {
            int num=abs(v[i]);
            if(v[num-1]>0) v[num-1]*=-1;
        }

        for(int i=0;i<v.size();i++)
        {
            if(v[i]>0) res.push_back(i+1);
        }

        return res;
    }
};
