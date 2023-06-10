// https://leetcode.com/problems/two-sum
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

class Solution {
public:

    vector<int> twoSum(vector<int>& v, int t) {

        vector<int> res;
        vector<int> u=v;
        int i=0,j=v.size()-1;

        sort(v.begin(),v.end());

        while(i<j)
        {
            int sum=v[i]+v[j];

            if(sum==t) break;  
            else if(sum>t) j--;
            else i++;
        }

        for(int idx=0;idx<v.size();idx++)
        {
            if(u[idx]==v[i]) res.push_back(idx);

            else if(u[idx]==v[j]) res.push_back(idx);
        }

        return res;
    }
};
