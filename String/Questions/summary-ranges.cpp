// https://leetcode.com/problems/summary-ranges

class Solution {
public:
    vector<string> summaryRanges(vector<int>& v) {

        vector<string> res;
        int i=0,j=0;

        while(i<v.size())
        {
            while(j+1<v.size() and v[j+1]==v[j]+1) j++;

            if(j>i) res.push_back(to_string(v[i])+"->"+to_string(v[j]));

            else res.push_back(to_string(v[j]));

            j++;
            i=j;
        }

        return res;
    }
};
