// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

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
