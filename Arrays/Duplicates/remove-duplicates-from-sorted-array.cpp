// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int i=0;

        for(int j=1;j<v.size();j++)
        {
            if(v[i]!=v[j]) 
            {
                i++;
                v[i]=v[j];
            }
        }

        return i+1;
    }
};
