// https://leetcode.com/problems/two-sum

// sort then 2 pointer to find ele that sun upto target t

class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        
        int i=0, j=v.size()-1;

        vector<int> u=v;
        vector<int> res;

        sort(v.begin(),v.end());

        while(i<j)
        {
            if(v[i]+v[j]==t) break;
            
            else if(v[i]+v[j]>t) j--;
            
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
