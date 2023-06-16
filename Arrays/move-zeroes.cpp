// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int i=0,j=1;

        while(j>i and j<v.size())
        {
            if(v[j]!=0 and v[i]==0)
            {
                swap(v[i],v[j]);
                i++;
                j++;
            }
            else if(v[j]==0 and v[i]==0)
            {
                j++;
            }
            else i++,j++;
        }
    }
};
